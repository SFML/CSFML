#!/bin/bash

# Automatically exit on error
set -e

if [[ -z "$1" ]]; then
    echo 'No Runtime Identifier specified, running all known RIDs'
    ./build.docker.sh "alpine-x64"
    ./build.docker.sh "debian-x64"
    ./build.docker.sh "fedora-x64"
    exit 0
fi

RID="$1"

case "$RID" in

'alpine-x64')
    Image='alpine'
    Shell='/bin/sh'
    ;;

'debian-x64')
    Image='debian'
    Shell='/bin/bash'
    ;;

'fedora-x64')
    Image='fedora'
    Shell='/bin/bash'
    ;;

*)
    echo "Unknown Runtime Identifier $RID"
    exit 1
    ;;

esac

echo "Building $RID using image $Image with $Shell"

RepoRoot="$(realpath "$(git rev-parse --show-toplevel)")"

docker run --rm --mount "type=bind,source=$RepoRoot,destination=/csfml/" "$Image" "$Shell" -c "cd /csfml/tools/nuget/; ./docker.$RID.sh"
