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
    echo "Usage: $0 <RID> [<cxx_compiler> <c_compiler>]"
    echo "Example: $0 linux-arm arm-linux-gnueabihf-g++ arm-linux-gnueabihf-gcc"
    exit 1
fi

echo "Please note that all SFML dependencies must be installed and available to cmake. SFML does not ship with its linux dependencies."

RID="$1"
CXX_COMPILER="$2"
C_COMPILER="$3"

if [[ -n "$CXX_COMPILER" || -n "$C_COMPILER" ]]; then
    if [[ -z "$CXX_COMPILER" || -z "$C_COMPILER" ]]; then
        echo "When overriding compilers, specify both C++ and C compilers."
        exit 1
    fi
fi

CMAKE_COMPILER_ARGS=()
if [[ -n "$CXX_COMPILER" ]]; then
    CMAKE_COMPILER_ARGS+=("-DCMAKE_CXX_COMPILER=$CXX_COMPILER" "-DCMAKE_C_COMPILER=$C_COMPILER")
    echo "Using custom compilers: CXX=$CXX_COMPILER, CC=$C_COMPILER"
fi

SFMLBranch="3.0.2" # The branch or tag of the SFML repository to be cloned
CSFMLDir="$(realpath ../../)"  # The directory of the source code of CSFML

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
    git clone --branch "$SFMLBranch" --depth 1 "https://github.com/SFML/SFML.git" "SFML"
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
    cmake "${CMAKE_COMPILER_ARGS[@]}" \
    '-DBUILD_SHARED_LIBS=ON' \
    '-DCMAKE_BUILD_TYPE=Release' \
    "-DCMAKE_INSTALL_PREFIX=$SFMLLibDir" \
    "-DCMAKE_LIBRARY_OUTPUT_DIRECTORY=$SFMLLibDir" \
    '-DCMAKE_BUILD_WITH_INSTALL_RPATH=ON' \
    '-DCMAKE_INSTALL_RPATH=$ORIGIN' \
    '-DSFML_USE_SYSTEM_DEPS=OFF' \
    '-DSFML_BUILD_NETWORK=OFF' \
    "$SFMLDir"

cmake --build . --config Release --target install

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
    cmake "${CMAKE_COMPILER_ARGS[@]}" \
    "-DSFML_ROOT=$SFMLLibDir" \
    '-DBUILD_SHARED_LIBS=ON' \
    '-DCMAKE_BUILD_TYPE=Release' \
    "-DCMAKE_LIBRARY_OUTPUT_DIRECTORY=$CSFMLLibDir" \
    '-DCMAKE_BUILD_WITH_INSTALL_RPATH=ON' \
    '-DCMAKE_INSTALL_RPATH=$ORIGIN' \
    '-DCSFML_BUILD_NETWORK=OFF' \
    "$CSFMLDir"
cmake --build . --config Release

# ======================================== #
# STEP 5: Copy result to the NuGet folders #
# ======================================== #

SFMLMajorMinor="3.0"
CSFMLMajorMinor="3.0"

# Copies one SFML and CSFML module into the NuGet package
# The module name must be passed to this function as an argument, in lowercase
# This function then copies $SFMLLibDir/libsfml-(module).so and
# $CSFMLLibDir/libcsfml-(module).so into $OutDir
copymodule()
{
    MODULE="$1"

    mkdir -p "$OutDir"

    # SFML.Net only searches for the name with common pre- and suffixes
    # As such we need to ship e.g. libcsfml-graphics.so
    # But the CSFML libs will look for the major.minor version
    # As such we also need to ship e.g. libcsfml-graphics.so.3.0
    # Unfortunately NuGet package don't support symlinks: https://github.com/NuGet/Home/issues/10734
    # For SFML, we can just ship one version that CSFML will be looking for
    cp "$SFMLLibDir/libsfml-$MODULE.so.$SFMLMajorMinor" "$OutDir"
    cp "$CSFMLLibDir/libcsfml-$MODULE.so" "$OutDir"
    cp "$CSFMLLibDir/libcsfml-$MODULE.so.$CSFMLMajorMinor" "$OutDir"
}

copymodule audio
copymodule graphics
copymodule system
copymodule window

popd # Pop CSFML
popd # Pop $RID
popd # Pop Build
