
set(INCROOT ${PROJECT_SOURCE_DIR}/include/CSFML/System)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/CSFML/System)

# all source files
set(SRC
    ${PROJECT_SOURCE_DIR}/include/CSFML/GPUPreference.h
    ${INCROOT}/Export.h
    ${SRCROOT}/Alloc.cpp
    ${INCROOT}/Alloc.h
    ${SRCROOT}/Buffer.cpp
    ${SRCROOT}/BufferStruct.hpp
    ${INCROOT}/Buffer.h
    ${SRCROOT}/Clock.cpp
    ${SRCROOT}/ClockStruct.hpp
    ${INCROOT}/Clock.h
    ${INCROOT}/InputStream.h
    ${SRCROOT}/Sleep.cpp
    ${INCROOT}/Sleep.h
    ${SRCROOT}/Time.cpp
    ${INCROOT}/Time.h
    ${INCROOT}/Types.h
    ${INCROOT}/Vector2.h
    ${INCROOT}/Vector3.h
)

# define the csfml-system target
csfml_add_library(csfml-system
                  SOURCES ${SRC}
                  DEPENDS SFML::System)
