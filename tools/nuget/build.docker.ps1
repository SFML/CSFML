Param(
    [Parameter(Position = 0)]
    [string] $RID
)

$ErrorActionPreference = "Stop"

if (-not $RID ) {
    Write-Output "No RID specified, building all known RIDs"
    ./build.docker.ps1 "alpine-x64"
    ./build.docker.ps1 "debian-x64"
    ./build.docker.ps1 "fedora-x64"
    exit
}

$Image = $null
$Shell = $null

switch ($RID) {
    'alpine-x64' { 
        $Image = 'alpine' 
        $Shell = '/bin/sh'
    }
    'debian-x64' { 
        $Image = 'debian' 
        $Shell = '/bin/bash'
    }
    'fedora-x64' { 
        $Image = 'fedora' 
        $Shell = '/bin/bash'
    }
    Default { 
        Write-Error "Unknown Runtime Identifier $RID"
        exit
    }
}

Write-Host "Building $RID with image $Image using $Shell"

$RepoRoot = (Get-Item (git rev-parse --show-toplevel)).FullName

docker run --rm --mount "type=bind,source=$RepoRoot,destination=/csfml/" $Image $Shell -c "cd /csfml/tools/nuget/; ./docker.$RID.sh"
exit $LastExitCode