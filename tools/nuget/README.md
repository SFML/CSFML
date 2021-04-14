# CSFML NuGet Packages
This directory contains all the files needed to build and package the native CSFML libraries for [SFML.Net](github.com/SFML/SFML.Net).
**All scripts must be run from the directory they are located in**. 
That means that your current working directory (`$PWD`) must be the same where the script is.

All build scripts follow the same routine:
1. Clone the SFML repository at `Build/SFML`, if it isn't already there
1. Configure & compile SFML with cmake inside of `Build/(RID)/SFML`, where `(RID)` is the [Runtime Identifier](https://docs.microsoft.com/en-us/dotnet/core/rid-catalog) for the target of the libraries being built
1. Configure & compile CSFML with cmake inside of `Build/(RID)/CSFML`
1. Copy the resulting libraries to `CSFML/runtimes/(RID)/native/`


* `build.win.ps1`
    * A [PowerShell](https://github.com/PowerShell/PowerShell) script to build Windows native libraries. By default, both `win-x86` and `win-x64` are built. To build only one specific Runtime Identifier, pass it to the script as a parameter (`./build.win.ps1 win-x64`)  
    You must have Visual Studio 2019, cmake, and the Windows SDK 10 installed to run this script.

* `build.linux.sh`
    * A [Bash](https://www.gnu.org/software/bash/) script to build libraries for a generic Linux distribution. The [Runtime Identifier](https://docs.microsoft.com/en-us/dotnet/core/rid-catalog) of the linux distribution must be specified as a parameter to the script.  
    This generic script doesn't install any of its dependencies. As such, you must have cmake and make installed, as well as all [SFML Dependencies](https://www.sfml-dev.org/tutorials/2.5/compile-with-cmake.php#installing-dependencies) available to cmake.

* `build.macos.sh`
    * A [Bash](https://www.gnu.org/software/bash/) script to build libraries for macOS. The [Runtime Identifier](https://docs.microsoft.com/en-us/dotnet/core/rid-catalog#macos-rids) of the macOS distribution must be specified as parameter to the script.
    Currently supported RIDs are:
        * osx.10.15-x64
        * osx.11.0-x64
        * osx.11.0-arm64 (requires SFML 2.6)

* `build.docker.sh`, `build.docker.ps1`
    * A script to build the native libraries for a Linux distribution in a Docker container. If no RID is specified as a parameter, all supported RIDs will be built. Currently, the supported RIDs are:
    * `alpine-x64` 
    * `debian-x64` (compatible with derivatives such as Ubuntu and Linux Mint)
    * `fedora-x64` 

* `pushnuget.ps1`, `pushnuget.sh`
    * A script to automatically build and push the NuGet package to nuget.org. Make sure that all the native libraries are in `CSFML/runtimes/` before running this.

* Other scripts
    * Any script not mentioned here is intended for internal use by other scripts only and shouldn't be called directly.
