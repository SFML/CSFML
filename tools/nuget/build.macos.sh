#!/bin/bash

# Automatically exit on error
set -e
set -x

# ========================= #
# PRELUDE: A note on rpaths #
# ========================= #

# Unlike Windows, macOS doesn't search the current directory by default when searching for shared libraries (.dylib)
# It only searches the system default directories (usually /lib and /usr/lib) and the paths in LD_LIBRARY_PATH

# The .NET Runtime will find the CSFML library in its NuGet packages just fine, but that library will then request
# the OS for libsfml-(module).dylib, and the .NET Runtime will have no say in how that SFML library is found.

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

# You may need to `brew install coreutils` first for grealpath
# See supported RID at https://docs.microsoft.com/en-us/dotnet/core/rid-catalog

# =================================================== #
# STEP 1: Setup all variables needed during the build #
# =================================================== #

if [[ -z "$1" ]]; then
    echo "Please specify the platform Runtime Identifier as an argument to this script"
    exit 1
fi

echo "Please note that all SFML dependencies must be installed and available to cmake. SFML does not ship with its linux dependencies."

RID="$1"

SFMLBranch="2.5.x" # The branch or tag of the SFML repository to be cloned
CSFMLDir="$(grealpath "$(git rev-parse --show-toplevel)")" # The directory of the source code of CSFML

OutDir="./CSFML/runtimes/$RID/native" # The base directory of all CSFML modules, used to copy the final libraries
mkdir -p "$OutDir"
OutDir="$(grealpath "$OutDir")"

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

SFMLDir="$(grealpath SFML)"

# ================== #
# STEP 3: Build SFML #
# ================== #

rm -rf "$RID"
mkdir -p "$RID"
pushd "$RID"

echo "Building SFML"
mkdir -p SFML
pushd SFML

SFMLBuiltDir="$(grealpath .)" # The directory where SFML was built to. Used later to direct cmake when building CSFML

mkdir -p lib
# The directory that contains the final SFML libraries
# Since linux libraries don't support static linking from a shared library, this is used to copy the
# SFML shared libraries together with the CSFML shared libraries into SFML.Net
SFMLLibDir="$(grealpath lib)"

if [ $RID == "osx-x64" ]; then
    ARCHITECTURE="x86_64"
    TARGET="10.12"
    SYSROOT="/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.12.sdk/"
elif [ $RID == "osx.11.0-x64" ]; then
    ARCHITECTURE="x86_64"
    TARGET="11.0"
    SYSROOT="/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX11.0.sdk/"
elif [ $RID == "osx.11.0-arm64" ]; then
    ARCHITECTURE="arm64"
    TARGET="11.0"
    SYSROOT="/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX11.0.sdk/"

    echo "Note: arm64 is only supported with SFML 2.6"
else
    echo "Unsupported RID provided. Use 'osx.10.15-x64', 'osx.11.0-x64' or 'osx.11.0-arm64'"
    exit 1
fi

cmake -E env \
    cmake -G "Unix Makefiles" \
          -D 'BUILD_SHARED_LIBS=ON' \
          -D 'SFML_BUILD_FRAMEWORKS=OFF' \
          -D 'CMAKE_BUILD_TYPE=Release' \
          -D "CMAKE_OSX_ARCHITECTURES=$ARCHITECTURE" \
          -D "CMAKE_OSX_DEPLOYMENT_TARGET=$TARGET" \
          -D "CMAKE_OSX_SYSROOT=$SYSROOT" \
          -D "CMAKE_LIBRARY_OUTPUT_DIRECTORY=$SFMLLibDir" \
          -D 'CMAKE_BUILD_WITH_INSTALL_RPATH=ON' \
          -D 'CMAKE_INSTALL_RPATH=@loader_path' \
          -D "CMAKE_INSTALL_PREFIX=$SFMLLibDir" \
          -D "SFML_DEPENDENCIES_INSTALL_PREFIX=$SFMLLibDir" \
          -D "SFML_MISC_INSTALL_PREFIX=$SFMLLibDir" \
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

cmake -E env \
    cmake -G "Unix Makefiles" \
          -D "SFML_DIR=$SFMLBuiltDir" \
          -D 'BUILD_SHARED_LIBS=ON' \
          -D 'CMAKE_BUILD_TYPE=Release' \
          -D "CMAKE_OSX_ARCHITECTURES=$ARCHITECTURE" \
          -D "CMAKE_OSX_DEPLOYMENT_TARGET=$TARGET" \
          -D "CMAKE_OSX_SYSROOT=$SYSROOT" \
          -D "CMAKE_LIBRARY_OUTPUT_DIRECTORY=$CSFMLLibDir" \
          -D 'CMAKE_BUILD_WITH_INSTALL_RPATH=ON' \
          -D 'CMAKE_INSTALL_RPATH=@loader_path' \
          -D "CMAKE_INSTALL_PREFIX=$CSFMLLibDir" \
          -D "INSTALL_MISC_DIR=$CSFMLLibDir" \
          "$CSFMLDir"
cmake --build . --config Release --target install

# ============================ #
# STEP 5: Fix RPATH references #
# ============================ #

SFMLMajorMinor="2.5"
SFMLMajorMinorPatch="$SFMLMajorMinor.1"

# SFML's framework dependencies will always reference @rpath/../Frameworks/<depedency>
# Which is not where we place the frameworks and where SFML should look for them
# This this fixes the dependency with install_name_tool
fixrpath()
{
    MODULE="$1"
    OLD="$2"
    NEW="$3"

    install_name_tool -change $OLD $NEW "$SFMLLibDir/libsfml-$MODULE.dylib"
    install_name_tool -change $OLD $NEW "$SFMLLibDir/libsfml-$MODULE.$SFMLMajorMinor.dylib"
    install_name_tool -change $OLD $NEW "$SFMLLibDir/libsfml-$MODULE.$SFMLMajorMinorPatch.dylib"
}

fixrpath audio "@rpath/../Frameworks/OpenAL.framework/Versions/A/OpenAL" "@rpath/OpenAL.framework/Versions/A/OpenAL"
fixrpath audio "@rpath/../Frameworks/vorbisenc.framework/Versions/A/vorbisenc" "@rpath/vorbisenc.framework/Versions/A/vorbisen"
fixrpath audio "@rpath/../Frameworks/vorbisfile.framework/Versions/A/vorbisfile" "@rpath/vorbisfile.framework/Versions/A/vorbisfile"
fixrpath audio "@rpath/../Frameworks/vorbis.framework/Versions/A/vorbis" "@rpath/vorbis.framework/Versions/A/vorbis"
fixrpath audio "@rpath/../Frameworks/ogg.framework/Versions/A/ogg" "@rpath/ogg.framework/Versions/A/ogg"
fixrpath audio "@rpath/../Frameworks/FLAC.framework/Versions/A/FLAC" "@rpath/FLAC.framework/Versions/A/FLAC"

fixrpath graphics "@rpath/../Frameworks/freetype.framework/Versions/A/freetype" "@rpath/freetype.framework/Versions/A/freetype"

# ======================================== #
# STEP 6: Copy result to the NuGet folders #
# ======================================== #

CSFMLMajorMinor="2.5"
CSFMLMajorMinorPatch="$CSFMLMajorMinor.2"

# Copies one SFML and CSFML module into the NuGet package
# The module name must be passed to this function as an argument, in lowercase
# This function then copies $SFMLLibDir/libsfml-(module).so and 
# $CSFMLLibDir/libcsfml-(module).so into $OutDir
copymodule()
{
    MODULE="$1"

    mkdir -p "$OutDir"

    # Note the wildcard at the end of the first argument
    # We are copying every versioned file here, not just the .dylib
    # (libsfml-audio.dylib, libsfml-audio.2.dylib, libsfml-audio.2.5.dylib, etc)
    # This is needed because of the way macOS searches for libraries based
    # one their SONAME
    cp "$SFMLLibDir/libsfml-$MODULE."* "$OutDir"

    cp "$CSFMLLibDir/libcsfml-$MODULE."* "$OutDir"

    # Fix naming for expected filename
    mv "$OutDir/libcsfml-$MODULE.dylib" "$OutDir/libcsfml-$MODULE"
    mv "$OutDir/libcsfml-$MODULE.$CSFMLMajorMinor.dylib" "$OutDir/libcsfml-$MODULE.$CSFMLMajorMinor"
    mv "$OutDir/libcsfml-$MODULE.$CSFMLMajorMinorPatch.dylib" "$OutDir/libcsfml-$MODULE.$CSFMLMajorMinorPatch"
}

copymodule audio
copymodule graphics
copymodule system
copymodule window

cp -R "$SFMLLibDir/"*.framework "$OutDir"

popd # Pop CSFML
popd # Pop $RID
popd # Pop Build
