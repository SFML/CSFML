set(INCROOT ${PROJECT_SOURCE_DIR}/include/CSFML/Network)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/CSFML/Network)

# all source files
set(SRC
    ${INCROOT}/Export.h
    ${SRCROOT}/Ftp.cpp
    ${SRCROOT}/FtpStruct.hpp
    ${INCROOT}/Ftp.h
    ${SRCROOT}/Http.cpp
    ${SRCROOT}/HttpStruct.hpp
    ${INCROOT}/Http.h
    ${SRCROOT}/IpAddress.cpp
    ${INCROOT}/IpAddress.h
    ${SRCROOT}/Packet.cpp
    ${SRCROOT}/PacketStruct.hpp
    ${INCROOT}/Packet.h
    ${SRCROOT}/SocketSelector.cpp
    ${SRCROOT}/SocketSelectorStruct.hpp
    ${INCROOT}/SocketSelector.h
    ${INCROOT}/SocketStatus.h
    ${SRCROOT}/TcpListener.cpp
    ${SRCROOT}/TcpListenerStruct.hpp
    ${INCROOT}/TcpListener.h
    ${SRCROOT}/TcpSocket.cpp
    ${SRCROOT}/TcpSocketStruct.hpp
    ${INCROOT}/TcpSocket.h
    ${INCROOT}/Types.h
    ${SRCROOT}/UdpSocket.cpp
    ${SRCROOT}/UdpSocketStruct.hpp
    ${INCROOT}/UdpSocket.h
)

# define the csfml-network target
csfml_add_library(csfml-network
                  SOURCES ${SRC}
                  DEPENDS SFML::Network)
