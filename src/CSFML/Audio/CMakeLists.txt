set(INCROOT ${PROJECT_SOURCE_DIR}/include/CSFML/Audio)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/CSFML/Audio)

# all source files
set(SRC
    ${INCROOT}/Export.h
    ${SRCROOT}/Listener.cpp
    ${INCROOT}/Listener.h
    ${SRCROOT}/Music.cpp
    ${SRCROOT}/MusicStruct.hpp
    ${INCROOT}/Music.h
    ${SRCROOT}/Sound.cpp
    ${SRCROOT}/SoundStruct.hpp
    ${INCROOT}/Sound.h
    ${SRCROOT}/SoundBuffer.cpp
    ${SRCROOT}/SoundBufferStruct.hpp
    ${INCROOT}/SoundBuffer.h
    ${SRCROOT}/SoundBufferRecorder.cpp
    ${SRCROOT}/SoundBufferRecorderStruct.hpp
    ${INCROOT}/SoundBufferRecorder.h
    ${SRCROOT}/SoundRecorder.cpp
    ${SRCROOT}/SoundRecorderStruct.hpp
    ${INCROOT}/SoundRecorder.h
    ${INCROOT}/SoundStatus.h
    ${SRCROOT}/SoundStream.cpp
    ${SRCROOT}/SoundStreamStruct.hpp
    ${INCROOT}/SoundStream.h
    ${INCROOT}/Types.h
)

# define the csfml-audio target
csfml_add_library(csfml-audio
                  SOURCES ${SRC}
                  DEPENDS SFML::Audio)
