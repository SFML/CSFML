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
    exit
}

$Generator = 'Visual Studio 17 2022'

switch ($RID) {
    'win-x86' {
        $Architecture = 'Win32'
    }
    'win-x64' {
        $Architecture = 'x64'
    }
    Default {
        Write-Error "Unknown RID '$RID'"
        exit
    }
}

Write-Output "Building $RID"
Write-Output "Using $Generator as the cmake generator"
Write-Output "Using architecture $Architecture"

$SFMLBranch = "3.0.0" # The branch or tag of the SFML repository to be cloned
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

IF ($RID -ne 'win-x86' -and $RID -ne 'win-x64') {
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
    "-G$Generator" `
    "-A$Architecture" `
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
    "-A$Architecture" `
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

Pop-Location # Pop CSFML
Pop-Location # Pop $RID
Pop-Location # Pop Build
