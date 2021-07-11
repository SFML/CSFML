#!/bin/sh

VERSION="2.5.1"
VERSION_C="2.5.1"
# BUILD_CSFML=FALSE
BUILD_CSFML=TRUE
BUILD_SFML=FALSE



###
### Create packages for SFML $VERSION on OS X
###
### Author: Marco Antognini <antognini.marco@gmail.com>
### Date: 15/11/2014
###

##
## SETTINGS
##
## Edit $VERSION & $VERSION_C above
##

sfml_giturl='https://github.com/SFML/SFML.git'
csfml_giturl='https://github.com/SFML/CSFML.git'

gittag="$VERSION"
gittag_c="$VERSION_C"

topdir=$(pwd)
tmpdir="$topdir/tmp/"

codedir="$tmpdir/code/"
cmakedir="$tmpdir/cmake/"
builddir="$tmpdir/build/"
installdir="$tmpdir/install/"

sfml_package_source_zip="$topdir/SFML-$gittag-sources.zip"
sfml_source_archive_url="https://github.com/SFML/SFML/archive/$gittag.zip"

sfml_package1070name="SFML-$gittag-macos-clang"
sfml_package1070="$topdir/$sfml_package1070name/"
sfml_archive1070="$sfml_package1070name.tar.gz"

csfml_package1070name="CSFML-$gittag_c-macos-clang"
csfml_package1070="$topdir/$csfml_package1070name/"
csfml_archive1070="$csfml_package1070name.tar.gz"

SDK1070="/Developer/SDKs/MacOSX10.7.sdk"

##
## HELPER FUNCTIONS
##

## Echoes to stderr, and die
error () # $* message to display
{
    echo "$@" 1>&2
    exit 2
}

## Check that the number of parameters is correct, or die
param_check () # $1 should be $# on call site,
               # $2 the number of required params,
               # $3 an id for the error message
{
    if [ $# -ne 3 ]
    then
        error "Internal error in param_error: the number of parameters is incorrect"
    fi

    if [ $1 -ne $2 ]
    then
        error "Internal error in $3: the number of parameters is incorrect"
    fi
}

## Check that the number of parameters is enough, or die
param_check_ge () # $1 should be $# on call site,
                  # $2 the minimal number of params,
                  # $3 an id for the error message
{
    param_check $# 3 "param_check_ge"

    if [ $1 -lt $2 ]
    then
        error "Internal error in $3: the number of parameters is not enough"
    fi
}

## Assert $1 is true, or die
assert () # $1: boolean, $2: an error message
{
    param_check $# 2 "assert"

    if [ $1 -ne 0 ]
    then
        error "$2"
    fi
}

## Create directory, or die
# === mkdir -p $1
create_dir () # $1: path
{
    param_check $# 1 "create_dir"
    mkdir -p "$1"
    assert $? "Couldn't create $1"
}

## Destroy and create directory, or die
re_create_dir () # $1: path
{
    param_check $# 1 "re_create_dir"
    destroy "$1"
    create_dir "$1"
}

## Destroy directory, or die
# === rm -fr $1
destroy () # $1: path
{
    param_check $# 1 "destroy"
    rm -fr "$1"
    assert $? "Couldn't destroy $1"
}

## [with root access] Destroy directory, or die
# === rm -fr $1
sudo_destroy () # $1: path
{
    param_check $# 1 "sudo_destroy"
    echo "sudo_destroy need root password for deleting $1"
    sudo rm -fr "$1"
    assert $? "Couldn't destroy $1"
}

## Destroy all paths, or die
destroy_all () # $1...N: paths
{
    param_check_ge $# 1 "destroy_all"

    for path in "$@"
    do
        destroy "$path"
    done
}

## [with root access] Destroy all paths, or die
sudo_destroy_all () # $1...N: paths
{
    param_check_ge $# 1 "sudo_destroy_all"

    for path in "$@"
    do
        sudo_destroy "$path"
    done
}

## Copy files/directories, recursively, or die
copy () # $1...N: src, $N+1: dest
{
    param_check_ge $# 2 "copy"
    cp -R "$@"
    assert $? "Couldn't copy $1 to $2"
}

## Go to dir with pushd, or die
push_pwd () # $1: path
{
    param_check $# 1 "push_pwd"
    pushd "$1"
    assert $? "Couldn't go to $1"
}

## Go back, or die
pop_pwd ()
{
    param_check $# 0 "pop_pwd"
    popd
    assert $? "Couldn't go back"
}

## Create a .tar.gz archive, or die
archive () # $1: src dir, $2: archive name
{
    param_check $# 2 "archive"

    push_pwd "$1/.."

    src=$(basename "$1")
    tar -zcvf "$2" "$src"
    assert $? "Zip failed for $2"

    pop_pwd
}

## Build SFML with CMake and Make, or die
build_sfml () # $1: 'clang' => clang & libc++
              # $2: 'frameworks'/'dylibs'
              # $3: 'doc'/'no doc'
              # $4: 'examples'/'no examples'
              # $5: 'templates'/'no templates'
              # $6: '10.7 SDK'
{
    param_check $# 6 "build_sfml"

    case "$1" in
        'clang')
            cxx="clang++"
            cc="clang"
            cxx_flags="-stdlib=libc++"
            cc_flags="-stdlib=libc++"
            ;;

        *)
            error "Unknown compiler for $1 in create_makefile"
            ;;
    esac

    case "$2" in
        'frameworks')
            frameworks="TRUE"
            installdir_adapted="$installdir/Library/Frameworks"
            ;;
        'dylibs')
            frameworks="FALSE"
            installdir_adapted="$installdir/usr/local"
            ;;
        *)
            error "Unknown option for $2 in create_makefile"
            ;;
    esac

    case "$3" in
        'doc')
            doc="TRUE"
            ;;
        'no doc')
            doc="FALSE"
            ;;
        *)
            error "Unknown option for $3 in create_makefile"
            ;;
    esac

    case "$4" in
        'examples')
            examples="TRUE"
            makeopts=""
            # NB: cannot use -j8 here because it bugs with cocoa example...
            ;;
        'no examples')
            examples="FALSE"
            makeopts="-j8"
            ;;
        *)
            error "Unknown option for $4 in create_makefile"
            ;;
    esac

    case "$5" in
        'templates')
            templates="TRUE"
            ;;
        'no templates')
            templates="FALSE"
            ;;
        *)
            error "Unknown option for $5 in create_makefile"
            ;;
    esac

    case "$6" in
        '10.7 SDK')
            target="10.7"
            sdk="$SDK1070"
            ;;
        *)
            error "Unknown option for $6 in create_makefile"
            ;;
    esac

    re_create_dir "$cmakedir"
    push_pwd "$cmakedir"

    cmake -G "Unix Makefiles" \
          -D "BUILD_SHARED_LIBS:BOOL=TRUE" \
          -D "CMAKE_BUILD_TYPE:STRING=Release" \
          -D "CMAKE_CXX_COMPILER:FILEPATH=/usr/bin/$cxx" \
          -D "CMAKE_CXX_FLAGS:STRING=$cxx_flags" \
          -D "CMAKE_C_COMPILER:FILEPATH=/usr/bin/$cc" \
          -D "CMAKE_C_FLAGS:STRING=$cc_flags" \
          -D "CMAKE_INSTALL_PREFIX:PATH=$installdir_adapted" \
          -D "SFML_DEPENDENCIES_INSTALL_PREFIX:STRING=$installdir/Library/Frameworks" \
          -D "SFML_MISC_INSTALL_PREFIX:STRING=$installdir/usr/local/share/SFML" \
          -D "CMAKE_OSX_ARCHITECTURES:STRING=x86_64" \
          -D "CMAKE_OSX_DEPLOYMENT_TARGET:STRING=$target" \
          -D "CMAKE_OSX_SYSROOT:STRING=$sdk" \
          -D "SFML_BUILD_DOC:BOOL=$doc" \
          -D "SFML_BUILD_EXAMPLES:BOOL=$examples" \
          -D "SFML_BUILD_FRAMEWORKS:BOOL=$frameworks" \
          -D "SFML_INSTALL_XCODE_TEMPLATES:BOOL=$templates" \
          "$codedir"
    assert $? "CMake failed"

    destroy "$installdir"

    make clean && make $makeopts && make install
    assert $? "Make failed"

    pop_pwd
}

## Build SFML with CMake and Make, or die
build_csfml () # $1: 'clang' => clang & libc++
               # $2: 'doc'/'no doc'
               # $3: '10.7 SDK'
{
    param_check $# 3 "build_csfml"

    case "$1" in
        'clang')
            cxx="clang++"
            cc="clang"
            cxx_flags="-stdlib=libc++"
            cc_flags="-stdlib=libc++"
            ;;

        *)
            error "Unknown compiler for $1 in create_makefile"
            ;;
    esac

    case "$2" in
        'doc')
            doc="TRUE"
            ;;
        'no doc')
            doc="FALSE"
            ;;
        *)
            error "Unknown option for $2 in create_makefile"
            ;;
    esac

    case "$3" in
        '10.7 SDK')
            target="10.7"
            sdk="$SDK1070"
            ;;
        *)
            error "Unknown option for $3 in create_makefile"
            ;;
    esac

    makeopts="-j8"

    re_create_dir "$cmakedir"
    push_pwd "$cmakedir"

    cmake -G "Unix Makefiles" \
          -D "BUILD_SHARED_LIBS:BOOL=TRUE" \
          -D "CMAKE_BUILD_TYPE:STRING=Release" \
          -D "CMAKE_CXX_COMPILER:FILEPATH=/usr/bin/$cxx" \
          -D "CMAKE_CXX_FLAGS:STRING=$cxx_flags" \
          -D "CMAKE_C_COMPILER:FILEPATH=/usr/bin/$cc" \
          -D "CMAKE_C_FLAGS:STRING=$cc_flags" \
          -D "CMAKE_INSTALL_PREFIX:PATH=$installdir/usr/local" \
          -D "CMAKE_OSX_ARCHITECTURES:STRING=x86_64" \
          -D "CMAKE_OSX_DEPLOYMENT_TARGET:STRING=$target" \
          -D "CMAKE_OSX_SYSROOT:STRING=$sdk" \
          -D "BUILD_DOC:BOOL=$doc" \
          -D "SFML_DIR:PATH=$sfml_package1070/Frameworks/SFML.framework/Versions/$gittag/Resources/CMake" \
          "$codedir"
    assert $? "CMake failed"

    destroy "$installdir"

    make clean && make $makeopts && make install
    assert $? "Make failed"

    pop_pwd
}

## Install a package (dylibs only) to compile CSFML later on, or die
minimal_install_package () # $1: path to package
{
    param_check $# 1 "install_package"

    push_pwd "$1"

    create_dir "/usr/local/share/SFML/cmake"
#    copy "cmake/Modules/FindSFML.cmake" "/usr/local/share/cmake/Modules/"
    copy "lib/" "/usr/local/lib/"
    copy "include/" "/usr/local/include/"

    pop_pwd
}

## Git clone, or die
clone () # $1: url, $2: dest, $3: branch or tag (also works with sha, but less efficiently)
{
    param_check $# 3 "clone"

    git clone "$1" --branch "$3" "$2" --depth 1 || git clone "$1" "$2" && git -C "$2" checkout "$3"
    assert $? "Cannot download the source code from $1"
}

## Remove anything related to SFML
wipe_sfml ()
{
    # Remove SFML from /usr/local
    destroy_all "/usr/local/include/SFML" \
                "/usr/local/lib/"libsfml-* \
                "/usr/local/share/SFML"

    # Remove SFML from /Library
    sudo_destroy_all "/Library/Frameworks/"sfml-* \
                     "/Library/Frameworks/SFML.framework"

    destroy_all "/Library/Developer/Xcode/Templates/SFML"
}

## Remove anything related to CSFML
wipe_csfml ()
{
    # Remove CSFML from /usr/local (that's it)
    destroy_all "/usr/local/include/CSFML" \
                "/usr/local/lib/"libcsfml-* \
                "/usr/local/share/CSFML"
}



##
## INITIALIZE
##


## Clean up before doing anything

wipe_sfml
wipe_csfml

destroy "$sfml_package_source_zip"
destroy_all "$sfml_archive1070" "$sfml_package1070"
destroy_all "$csfml_archive1070" "$csfml_package1070"
destroy "$tmpdir"


##
## CREATE SOURCE ARCHIVE
##
# we need to do it on a Unix compatible system to keep symlinks valid in frameworks extlibs

wget -O "$sfml_package_source_zip" "$sfml_source_archive_url"
assert $? "Couldn't download the source archive"
zip -d "$sfml_package_source_zip" "SFML-$gittag/.gitattributes"
assert $? "Couldn't remove extra files from source archive"


##
## DOWNLOAD SFML
##


## First, download the code from github

destroy "$codedir"
clone "$sfml_giturl" "$codedir" "$gittag"

##
## BUILD SFML FOR 1070
##


# Now configure CMake for 10.7, 64bits, clang & libc++, doc, example, templates, FRAMEWORKS
# and build SFML !

build_sfml 'clang' 'frameworks' 'doc' 'examples' 'templates' '10.7 SDK'


## Copy the results to the package dir

re_create_dir "$sfml_package1070"

copy "$installdir/usr/local/share/SFML/" \
     "$sfml_package1070/"

create_dir "$sfml_package1070/extlibs/"
copy "$installdir/Library/Frameworks/FLAC.framework" \
     "$installdir/Library/Frameworks/freetype.framework" \
     "$installdir/Library/Frameworks/ogg.framework" \
     "$installdir/Library/Frameworks/OpenAL.framework" \
     "$installdir/Library/Frameworks/vorbis.framework" \
     "$installdir/Library/Frameworks/vorbisenc.framework" \
     "$installdir/Library/Frameworks/vorbisfile.framework" \
     "$sfml_package1070/extlibs/"

create_dir "$sfml_package1070/Frameworks/"
copy "$installdir/Library/Frameworks/"sfml-* \
     "$installdir/Library/Frameworks/SFML.framework" \
     "$sfml_package1070/Frameworks/"

create_dir "$sfml_package1070/templates/"
copy "/Library/Developer/Xcode/Templates/SFML" \
     "$sfml_package1070/templates/"


## Now configure CMake for 10.7, 64bits, clang & libc++, DYLIBS

build_sfml 'clang' 'dylibs' 'no doc' 'no examples' 'no templates' '10.7 SDK'


## Copy the results to the package dir

create_dir "$sfml_package1070/include/"
copy "$installdir/usr/local/include/SFML" \
     "$sfml_package1070/include/"

create_dir "$sfml_package1070/lib/"
copy "$installdir/usr/local/lib/"libsfml-* \
     "$sfml_package1070/lib/"

copy "$codedir/changelog.md" \
     "$sfml_package1070/"



## Clean up some files

find "$sfml_package1070" -regex '.*/\.DS_Store' -delete
assert $? "Find failed while removing extra files"
find "$sfml_package1070" -regex '.*/*\.swp' -delete
assert $? "Find failed while removing extra files"
find "$sfml_package1070" -regex '.*/*~' -delete
assert $? "Find failed while removing extra files"


## Apply patch for templates to fix paths

curl -fsSl "template.2.5.0.patch" | patch "$sfml_package1070/templates/SFML/SFML App.xctemplate/TemplateInfo.plist" --no-backup-if-mismatch
assert $? "Couldn't apply patch on templates"


## And create archives

destroy "$tmpdir"

archive "$sfml_package1070" "$sfml_archive1070"

if [ $BUILD_CSFML != "TRUE" ]
then
    echo "I'M NOT BUILDING CSFML!"
    exit 0
fi

##
## DOWNLOAD CSFML
##

destroy "$codedir"
clone "$csfml_giturl" "$codedir" "$gittag_c"


##
## BUILD CSFML FOR 1070
##

wipe_sfml
minimal_install_package "$sfml_package1070"

build_csfml 'clang' 'doc' '10.7 SDK'

create_dir "$csfml_package1070/include/"
copy "$installdir/usr/local/include/SFML" \
     "$csfml_package1070/include/"

create_dir "$csfml_package1070/lib/"
copy "$installdir/usr/local/lib/"libcsfml-* \
     "$csfml_package1070/lib/"

copy "$installdir/usr/local/share/CSFML/" \
     "$csfml_package1070/"


##
## CLEAN UP & ARCHIVE
##

find "$csfml_package1070" -regex '.*/\.DS_Store' -delete
assert $? "Find failed while removing extra files"
find "$csfml_package1070" -regex '.*/*\.swp' -delete
assert $? "Find failed while removing extra files"
find "$csfml_package1070" -regex '.*/*~' -delete
assert $? "Find failed while removing extra files"

## Clean up temporary directories
## And create archives

destroy "$tmpdir"

archive "$csfml_package1070" "$csfml_archive1070"



### End Of Script

