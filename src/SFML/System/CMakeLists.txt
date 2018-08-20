
set(INCROOT ${CMAKE_SOURCE_DIR}/include/SFML/System)
set(SRCROOT ${CMAKE_SOURCE_DIR}/src/SFML/System)

# all source files
set(SRC
    ${CMAKE_SOURCE_DIR}/include/SFML/GPUPreference.h
    ${INCROOT}/Export.h
    ${SRCROOT}/Clock.cpp
    ${SRCROOT}/ClockStruct.h
    ${INCROOT}/Clock.h
    ${INCROOT}/InputStream.h
    ${SRCROOT}/Mutex.cpp
    ${SRCROOT}/MutexStruct.h
    ${INCROOT}/Mutex.h
    ${SRCROOT}/Sleep.cpp
    ${INCROOT}/Sleep.h
    ${SRCROOT}/Thread.cpp
    ${SRCROOT}/ThreadStruct.h
    ${INCROOT}/Thread.h
    ${SRCROOT}/Time.cpp
    ${INCROOT}/Time.h
    ${INCROOT}/Types.h
    ${INCROOT}/Vector2.h
    ${INCROOT}/Vector3.h
)

# define the csfml-system target
csfml_add_library(csfml-system
                  SOURCES ${SRC}
                  DEPENDS sfml-system)
