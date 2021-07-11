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

$Generator = 'Visual Studio 16 2019'

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

$SFMLBranch = "2.5.1" # The branch or tag of the SFML repository to be cloned
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
        exit
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

    git clone --branch "$SFMLBranch" --depth 1 "git://github.com/SFML/SFML.git" "SFML"
    Ensure-Success
}

Push-Location "SFML"

$SFMLDir = (Get-Item .).FullName

switch ($RID) {
    'win-x86' { 
        $SFMLExtLibs = (Get-Item ./extlibs/libs-msvc-universal/x86).FullName
        $SFMLAudioExtras = (Get-Item ./extlibs/bin/x86).FullName
    }
    'win-x64' { 
        $SFMLExtLibs = (Get-Item ./extlibs/libs-msvc-universal/x64).FullName
        $SFMLAudioExtras = (Get-Item ./extlibs/bin/x64).FullName
    }
    Default {
        Write-Error "Unknown RID '$RID'"
        exit
    }
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

cmake `
    '-DBUILD_SHARED_LIBS=0' `
    '-DCMAKE_BUILD_TYPE=Release' `
    '-DCMAKE_SYSTEM_VERSION=8.1' `
    '-DSFML_USE_STATIC_STD_LIBS=1' `
    "-G$Generator" `
    "-A$Architecture" `
    $SFMLDir
Ensure-Success

cmake --build . --config Release -- '-verbosity:minimal'
Ensure-Success

Pop-Location # Pop SFML

# =================== #
# STEP 4: Build CSFML #
# =================== #

Write-Output "Building CSFML using SFML at $SFMLBuiltDir"
New-Push CSFML

New-Item -ItemType Directory lib > $null
$CSFMLLibDir = (Get-Item lib).FullName; # The directory where the final CSFML dlls are located

cmake `
    "-DSFML_DIR=$SFMLBuiltDir" `
    '-DCSFML_LINK_SFML_STATICALLY=1' `
    "-DCMAKE_LIBRARY_PATH=$SFMLExtLibs" `
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
    '-DSTATIC_STD_LIBS=1' `
    `
    "-DBUILD_SHARED_LIBS=1" `
    '-DCMAKE_BUILD_TYPE=Release' `
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
Copies a specific CSFML module into its proper NuGet project

.DESCRIPTION
This function locates a file named csfml-(module)-2.dll inside of the
folder specified by $CSFMLLibDir and copies it to $OutDir/csfml-(module).dll.

Notice how it removes the "-2" at the end, to make the name compatible with other platforms.

.PARAMETER module
The case-insensitive name of the module to copy.
#>
function Copy-Module($module) {
    Write-Output "Copying CSFML $module"

    New-Item -ItemType Directory $OutDir -ErrorAction Ignore > $null
    Copy-Item "$CSFMLLibDir/csfml-$module-2.dll" "$OutDir/csfml-$module.dll" -Force > $null
}

Copy-Module 'audio'
Copy-Module 'graphics'
Copy-Module 'system'
Copy-Module 'window'

Write-Output "Copying Audio module extra files"
Copy-Item "$SFMLAudioExtras/*" "$OutDir"

Pop-Location # Pop CSFML
Pop-Location # Pop $RID
Pop-Location # Pop Build