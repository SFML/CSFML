[![SFML logo](https://www.sfml-dev.org/images/logo.png)](https://www.sfml-dev.org)

# CSFML - Simple and Fast Multimedia Library for C

SFML is a simple, fast, cross-platform and object-oriented multimedia API. It provides access to windowing, graphics, audio and network. It is originally written in C++, and this project is its official binding for the C language.

## State of Development

Development is focused on version 3 in the `master` branch. No more features are planned for the 2.x release series.

## Authors

  - Laurent Gomila (laurent@sfml-dev.org)
  - Lukas Dürrenberger (eXpl0it3r@sfml-dev.org)
  - Chris Thrasher (thrasher@sfml-dev.org)
  - Zachariah Brown (contact@zbrown.net)
  - And many other members of the SFML community

## Download

You can get the latest official release on [SFML website](https://www.sfml-dev.org/download/csfml). You can also get the current development version from the [Git repository](https://github.com/SFML/CSFML).

## Learn

There is no tutorial for CSFML, but since it's a binding you can use the C++ resources:

  * The [official tutorials](https://www.sfml-dev.org/tutorials/)
  * The [online API documentation](https://www.sfml-dev.org/documentation/)
  * The [community wiki](https://github.com/SFML/SFML/wiki/)
  * The [community forum](https://en.sfml-dev.org/forums/) (or [French](https://fr.sfml-dev.org/forums/))

Of course, you can also find the CSFML API documentation in the SDK.

## Building

Building CSFML follows typical CMake conventions.
Here's how to get started.

1. Install SFML.
This may be done in a variety of ways including using a system package manager or building and installing SFML from source.
The major version of SFML must match the major version of CSFML.
2. Configure CSFML.
If you are building CSFML for the purpose of contributing, we recommend using the `dev` CMake preset.
This will enable a number of useful settings related to developing the library.
If needed, set the `SFML_ROOT` CMake variable to tell CMake where to find your installation of SFML.
The `CSFML_LINK_SFML_STATICALLY` option must align with whether your installation of SFML uses static or shared libraries.
3. Build CSFML.
The `install` target will install all public headers and libraries.

## Contribute

SFML and CSFML are open-source projects, and they need your help to go on growing and improving. Don't hesitate to post suggestions or bug reports on [the forum](https://en.sfml-dev.org/forums/), or post new bugs/features requests on the [issue tracker](https://github.com/SFML/CSFML/issues/). You can even fork the project on GitHub, maintain your own version and send us pull requests periodically to merge your work.
