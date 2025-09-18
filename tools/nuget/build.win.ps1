Param(
    [Parameter(Position = 0)]
    [string] $RID
)

$ErrorActionPreference = "Stop"

# =================================================== #
# STEP 1: Setup all variables needed during the build #
# =================================================== #

if (-not $RID) {
    Write-Output "No RID specified, building all known RIDs"
    ./build.win.ps1 "win-x86"
    ./build.win.ps1 "win-x64"
    ./build.win.ps1 "win-arm64"
    exit
}

$Generator = 'Visual Studio 17 2022'

# See also: https://learn.microsoft.com/en-us/dotnet/core/rid-catalog#known-rids
switch ($RID) {
    'win-x86' {
        $ArchitectureCMake = 'Win32'
        $Architecture = 'x86'
    }
    'win-x64' {
        $ArchitectureCMake = 'x64'
        $Architecture = 'x64'
    }
    'win-arm64' {
        $ArchitectureCMake = 'ARM64'
        $Architecture = 'arm64'
    }
    Default {
        Write-Error "Unknown RID '$RID'"
        exit
    }
}

Write-Output "Building $RID"
Write-Output "Using $Generator as the cmake generator"
Write-Output "Using architecture $ArchitectureCMake"

$SFMLBranch = "3.0.2" # The branch or tag of the SFML repository to be cloned
$CSFMLDir = (Get-Item (git rev-parse --show-toplevel)).FullName # The directory of the source code of CSFML

$OutDir = "./CSFML/runtimes/$RID/native" # The directory of all CSFML modules, used to copy the final dlls
New-Item -ItemType Directory -ErrorAction Ignore $OutDir > $null
$OutDir = (Get-Item $OutDir).FullName

<#
.SYNOPSIS
Ensures that the last command run was a success, checking its exit code.
#>
function Ensure-Success() {
    if ($LastExitCode -ne 0) {
        exit -1
    }
}

<#
.SYNOPSIS
Creates a new subdirectory of the current working directory and pushes it into the directory
stack with Push-Location, so that it can be reverted with Pop-Location.

.PARAMETER path
The path to create and push.
#>
function New-Push($path) {
    New-Item -ItemType Directory -ErrorAction Ignore $path > $null
    Push-Location $path > $null
}

New-Push "Build"

# ================== #
# STEP 2: Clone SFML #
# ================== #

If (-not (Test-Path "SFML/.git")) {
    Write-Output "Cloning SFML"
    Remove-Item -Recurse -Force -ErrorAction Ignore "SFML" > $null

    git clone --branch "$SFMLBranch" --depth 1 "https://github.com/SFML/SFML.git" "SFML"
    Ensure-Success
}

Push-Location "SFML"

$SFMLDir = (Get-Item .).FullName

IF ($RID -ne 'win-x86' -and $RID -ne 'win-x64' -and $RID -ne 'win-arm64') {
    Write-Error "Unknown RID '$RID'"
    exit
}

Pop-Location # Pop SFML

# ================== #
# STEP 3: Build SFML #
# ================== #

Remove-Item -Recurse -Force -ErrorAction Ignore "$RID"
New-Push "$RID"


Write-Output "Building SFML"
New-Push SFML

$SFMLBuiltDir = Get-Location # The directory where SFML was built to. Used later to direct cmake when building CSFML
$SFMLInstallDir = Join-Path -Path $SFMLBuiltDir -ChildPath 'install'

cmake `
    '-DBUILD_SHARED_LIBS=ON' `
    '-DCMAKE_BUILD_TYPE=Release' `
    '-DCMAKE_SYSTEM_VERSION=8.1' `
    '-DSFML_USE_STATIC_STD_LIBS=OFF' `
    '-DSFML_BUILD_NETWORK=OFF' `
    "-DCMAKE_INSTALL_PREFIX=$SFMLInstallDir" `
    "-DCMAKE_POLICY_VERSION_MINIMUM=3.5" `
    "-G$Generator" `
    "-A$ArchitectureCMake" `
    $SFMLDir
Ensure-Success

cmake --build . --config Release --target install -- '-verbosity:minimal'
Ensure-Success

Pop-Location # Pop SFML

# =================== #
# STEP 4: Build CSFML #
# =================== #

Write-Output "Building CSFML using SFML at $SFMLInstallDir"
New-Push CSFML

New-Item -ItemType Directory lib > $null
$CSFMLLibDir = (Get-Item lib).FullName; # The directory where the final CSFML dlls are located

cmake `
    "-DSFML_ROOT=$SFMLInstallDir" `
    '-DCSFML_LINK_SFML_STATICALLY=OFF' `
    `
    "-DCMAKE_LIBRARY_OUTPUT_DIRECTORY=$CSFMLLibDir" `
    "-DCMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE=$CSFMLLibDir" `
    `
    "-DCMAKE_ARCHIVE_OUTPUT_DIRECTORY=$CSFMLLibDir" `
    "-DCMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE=$CSFMLLibDir" `
    `
    "-DCMAKE_RUNTIME_OUTPUT_DIRECTORY=$CSFMLLibDir" `
    "-DCMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE=$CSFMLLibDir" `
    `
    '-DCMAKE_SYSTEM_VERSION=8.1' `
    '-DCSFML_USE_STATIC_STD_LIBS=OFF' `
    `
    '-DBUILD_SHARED_LIBS=ON' `
    '-DCMAKE_BUILD_TYPE=Release' `
    '-DCSFML_BUILD_NETWORK=OFF' `
    `
    "-G$generator" `
    "-A$ArchitectureCMake" `
    `
    $CSFMLDir
Ensure-Success

cmake --build . --config Release -- '-verbosity:minimal'
Ensure-Success

# ======================================== #
# STEP 5: Copy result to the NuGet folders #
# ======================================== #

Write-Output "Copying CSFML modules"

<#
.SYNOPSIS
Copies a specific SFML & CSFML module into its proper NuGet project

.DESCRIPTION
This function locates a file named csfml-(module)-3.dll inside of the
folder specified by $CSFMLLibDir and copies it to $OutDir/csfml-(module).dll.

Notice how it removes the "-3" at the end, to make the name compatible with other platforms.

The "-3" prefix is retained for the SFML libraries.

.PARAMETER module
The case-insensitive name of the module to copy.
#>
function Copy-Module($module) {
    Write-Output "Copying SFML & CSFML $module"

    New-Item -ItemType Directory $OutDir -ErrorAction Ignore > $null
    Copy-Item "$SFMLInstallDir/bin/sfml-$module-3.dll" "$OutDir" -Force > $null
    Copy-Item "$CSFMLLibDir/csfml-$module-3.dll" "$OutDir/csfml-$module.dll" -Force > $null
}

Copy-Module 'audio'
Copy-Module 'graphics'
Copy-Module 'system'
Copy-Module 'window'

# ====================================================== #
# STEP 6: Copy the required runtime to the NuGet folders #
# ====================================================== #

<#
.SYNOPSIS
Copies the required and allowed redistributable runtime DLLs to the NuGet folders.

.DESCRIPTION
Since we're no longer linking statically against the runtime, we need to ensure
that the required redistributable DLLs are included in the NuGet package.
Microsoft only allows the distribution of the DLLs listed in the redist.txt, as
such we make sure to only include those.
Additionally, we're checking what the DLLs actually depend on with dumpbin.exe
and make sure to find those dependencies.
#>

# Locate VS installation
$vswhere = "${env:ProgramFiles(x86)}\Microsoft Visual Studio\Installer\vswhere.exe"
if (-not (Test-Path $vswhere)) {
    throw "vswhere.exe not found"
}

$vsPath = & $vswhere -latest -products * -requires Microsoft.VisualStudio.Component.VC.Redist.* -property installationPath
if (-not $vsPath) {
    throw "Could not locate Visual Studio installation with VC++ Redist components"
}

# Find latest VC redist directory
$redistRoot = Join-Path $vsPath "VC\Redist\MSVC"
$latestRedist = Get-ChildItem $redistRoot -Directory -Exclude "v*" | Sort-Object Name -Descending | Select-Object -First 1
$redistCRT = Join-Path $latestRedist.FullName "$Architecture\Microsoft.VC*" 

Write-Host "Using CRT redistributables from $redistCRT"

# Get list of DLLs in redistributable CRT directory
$redistributableDlls = Get-ChildItem -Path $redistCRT -Recurse -Filter *.dll | Select-Object -ExpandProperty Name

# Check binary dependencies
function Get-BinaryDependencies {
    param([string]$Path)

    $dumpbin = Get-Command dumpbin.exe -ErrorAction SilentlyContinue
    if (-not $dumpbin) {
        $dumpbin = Get-ChildItem -Path $vsPath -Recurse -Filter dumpbin.exe -ErrorAction SilentlyContinue | Where-Object { $_.FullName -match "\\$Architecture\\" } -ErrorAction SilentlyContinue | Select-Object -First 1
    }
    if (-not $dumpbin) { throw "dumpbin.exe not found" }

    & $dumpbin /DEPENDENTS $Path | Where-Object { $_ -match "\.DLL" } | ForEach-Object { $_.Trim() }
}

# Process binaries
Get-ChildItem $OutDir -Filter *.dll | ForEach-Object {
    $dll = $_.FullName
    Write-Host "Checking dependencies for $dll"

    $deps = Get-BinaryDependencies -Path $dll
    foreach ($dep in $deps) {
        if ($redistributableDlls -contains $dep) {
            $source = Get-ChildItem -Path $redistCRT -Recurse -Filter $dep | Select-Object -First 1
            if ($source) {
                Copy-Item $source.FullName -Destination $OutDir -Force
                Write-Host " -> Copied $dep from $($source.DirectoryName)"
            }
        }
    }
}

Pop-Location # Pop CSFML
Pop-Location # Pop $RID
Pop-Location # Pop Build
