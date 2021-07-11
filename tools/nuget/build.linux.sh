#!/bin/bash

# Automatically exit on error
set -e

# ========================= #
# PRELUDE: A note on rpaths #
# ========================= #

# Unlike Windows, Linux doesn't search the current directory by default when searching for shared libraries (.so)
# It only searches the system default directories (usually /lib and /usr/lib) and the paths in LD_LIBRARY_PATH

# The .NET Runtime will find the CSFML library in its NuGet packages just fine, but that library will then request
# the OS for libsfml-(module).so, and the .NET Runtime will have no say in how that SFML library is found.

# Without SFML installed globally on the system, this will fail, causing the loading of CSFML to fail, causing the
# .NET Runtime to think the CSFML library doesn't exist or is invalid.

# And so, we need to set the rpath of the CSFML library.
# The rpath is a special value embedded straight into a library that specifies to the OS a list of folders where
# other libraries that it references may be found.
# $ORIGIN, a kind-of environment variable, can be used in rpath to point to the folder where the library currently is.
# To let the OS know that we intend to use $ORIGIN, we need to add the ORIGIN flag to our ELF with the -z origin
# gcc linker option

# Since CSFML and SFML will always be deployed on the same folder by NuGet, we just need to add an rpath to CSFML
# that points to $ORIGIN, causing the OS to search the current folder for SFML, without interference from .NET

# We also add the same rpath to SFML itself for future-proofing, in case we ever decide to ship some Linux SFML
# dependencies on the Native package.

# =================================================== #
# STEP 1: Setup all variables needed during the build #
# =================================================== #

if [[ -z "$1" ]]; then
    echo "Please specify the platform Runtime Identifier as an argument to this script"
    exit 1
fi

echo "Please note that all SFML dependencies must be installed and available to cmake. SFML does not ship with its linux dependencies."

RID="$1"

SFMLBranch="2.5.1" # The branch or tag of the SFML repository to be cloned
CSFMLDir="$(realpath "$(git rev-parse --show-toplevel)")"  # The directory of the source code of CSFML

OutDir="./CSFML/runtimes/$RID/native" # The base directory of all CSFML modules, used to copy the final libraries
mkdir -p "$OutDir"
OutDir="$(realpath "$OutDir")"

echo "Building $RID"

mkdir -p "Build"
pushd "Build"

# ================== #
# STEP 2: Clone SFML #
# ================== #

if [[ ! -d "SFML/.git" ]]; then
    echo "Cloning SFML"
    rm -rf "SFML"
    git clone --branch "$SFMLBranch" --depth 1 "git://github.com/SFML/SFML.git" "SFML"
fi

SFMLDir="$(realpath SFML)"

# ================== #
# STEP 3: Build SFML #
# ================== #

rm -rf "$RID"
mkdir -p "$RID"
pushd "$RID"

echo "Building SFML"
mkdir -p SFML
pushd SFML

SFMLBuiltDir="$(realpath .)" # The directory where SFML was built to. Used later to direct cmake when building CSFML

mkdir -p lib
# The directory that contains the final SFML libraries
# Since linux libraries don't support static linking from a shared library, this is used to copy the
# SFML shared libraries together with the CSFML shared libraries into SFML.Net
SFMLLibDir="$(realpath lib)"

cmake -E env LDFLAGS="-z origin" \
    cmake \
    '-DBUILD_SHARED_LIBS=1' \
    '-DCMAKE_BUILD_TYPE=Release' \
    "-DCMAKE_LIBRARY_OUTPUT_DIRECTORY=$SFMLLibDir" \
    '-DCMAKE_BUILD_WITH_INSTALL_RPATH=1' \
    '-DCMAKE_INSTALL_RPATH=$ORIGIN' \
    "$SFMLDir"

cmake --build . --config Release

popd # Pop SFML

# =================== #
# STEP 4: Build CSFML #
# =================== #

echo "Building CSFML using SFML at $SFMLBuiltDir"
mkdir -p CSFML
pushd CSFML

mkdir -p lib
CSFMLLibDir="$(realpath lib)" # The directory that contains the final CSFML libraries. Used to copy the result into SFML.Net

cmake -E env LDFLAGS="-z origin" \
    cmake \
    "-DSFML_DIR=$SFMLBuiltDir" \
    '-DBUILD_SHARED_LIBS=1' \
    '-DCMAKE_BUILD_TYPE=Release' \
    "-DCMAKE_LIBRARY_OUTPUT_DIRECTORY=$CSFMLLibDir" \
    '-DCMAKE_BUILD_WITH_INSTALL_RPATH=1' \
    '-DCMAKE_INSTALL_RPATH=$ORIGIN' \
    "$CSFMLDir"
cmake --build . --config Release

# ======================================== #
# STEP 5: Copy result to the NuGet folders #
# ======================================== #

# Copies one SFML and CSFML module into the NuGet package
# The module name must be passed to this function as an argument, in lowercase
# This function then copies $SFMLLibDir/libsfml-(module).so and 
# $CSFMLLibDir/libcsfml-(module).so into $OutDir
copymodule()
{
    MODULE="$1"

    mkdir -p "$OutDir"

    # Note the wildcard at the end of the first argument
    # We are copying every versioned file here, not just the .so
    # (libsfml-audio.so, libsfml-audio.so.2, libsfml-audio.so.2.5, etc)
    # This is needed because of the way linux searches for libraries based
    # one their SONAME
    cp "$SFMLLibDir/libsfml-$MODULE.so"* "$OutDir"

    cp "$CSFMLLibDir/libcsfml-$MODULE.so" "$OutDir"
}

copymodule audio
copymodule graphics
copymodule system
copymodule window

popd # Pop CSFML
popd # Pop $RID
popd # Pop Build
