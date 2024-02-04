Param(
    [Parameter(Position = 0)]
    [string] $RID
)

$ErrorActionPreference = "Stop"

if (-not $RID ) {
    Write-Output "No RID specified, building all common RIDs"
    ./build.docker.ps1 "linux-x64"
    ./build.docker.ps1 "linux-musl-x64"
    ./build.docker.ps1 "linux-arm"
    ./build.docker.ps1 "linux-arm64"
    exit
}

$Image = $null
$Shell = $null

switch ($RID) {
    'alpine-x64' {
        $Image = 'alpine:3.7'
        $Shell = '/bin/sh'
    }
    'debian-x64' {
        $Image = 'debian:bullseye'
        $Shell = '/bin/bash'
    }
    'ubuntu-x64' {
        $Image = 'ubuntu:22.04'
        $Shell = '/bin/bash'
    }
    'fedora-x64' {
        $Image = 'fedora:37'
        $Shell = '/bin/bash'
    }
    'linux-x64' {
        $Image = 'ubuntu:22.04'
        $Shell = '/bin/bash'
    }
    'linux-musl-x64' {
        $Image = 'alpine:3.15'
        $Shell = '/bin/sh'
    }
    'linux-arm' {
        $Image = 'arm32v7/ubuntu:22.04'
        $Shell = '/bin/bash'
    }
    'linux-arm64' {
        $Image = 'arm64v8/ubuntu:24.04'
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
