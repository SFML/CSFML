////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2018 Laurent Gomila (laurent@sfml-dev.org)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Network/Packet.h>
#include <SFML/Network/PacketStruct.h>
#include <SFML/Internal.h>


////////////////////////////////////////////////////////////
sfPacket* sfPacket_create(void)
{
    return new sfPacket;
}


////////////////////////////////////////////////////////////
sfPacket* sfPacket_copy(const sfPacket* packet)
{
    CSFML_CHECK_RETURN(packet, NULL);

    return new sfPacket(*packet);
}


////////////////////////////////////////////////////////////
void sfPacket_destroy(sfPacket* packet)
{
    delete packet;
}


////////////////////////////////////////////////////////////
void sfPacket_append(sfPacket* packet, const void* data, size_t sizeInBytes)
{
    CSFML_CALL(packet, append(data, sizeInBytes));
}


////////////////////////////////////////////////////////////
void sfPacket_clear(sfPacket* packet)
{
    CSFML_CALL(packet, clear());
}


////////////////////////////////////////////////////////////
const void* sfPacket_getData(const sfPacket* packet)
{
    CSFML_CALL_RETURN(packet, getData(), NULL);
}


////////////////////////////////////////////////////////////
size_t sfPacket_getDataSize(const sfPacket* packet)
{
    CSFML_CALL_RETURN(packet, getDataSize(), 0);
}


////////////////////////////////////////////////////////////
sfBool sfPacket_endOfPacket(const sfPacket* packet)
{
    CSFML_CALL_RETURN(packet, endOfPacket(), sfFalse);
}


////////////////////////////////////////////////////////////
sfBool sfPacket_canRead(const sfPacket* packet)
{
    CSFML_CHECK_RETURN(packet, sfFalse);
    return packet->This ? sfTrue : sfFalse;
}


////////////////////////////////////////////////////////////
sfBool sfPacket_readBool(sfPacket* packet)
{
    return sfPacket_readUint8(packet);
}
sfInt8 sfPacket_readInt8(sfPacket* packet)
{
    CSFML_CHECK_RETURN(packet, sfFalse);
    sfInt8 value;
    packet->This >> value;
    return value;
}
sfUint8 sfPacket_readUint8(sfPacket* packet)
{
    CSFML_CHECK_RETURN(packet, sfFalse);
    sfUint8 value;
    packet->This >> value;
    return value;
}
sfInt16 sfPacket_readInt16(sfPacket* packet)
{
    CSFML_CHECK_RETURN(packet, sfFalse);
    sfInt16 value;
    packet->This >> value;
    return value;
}
sfUint16 sfPacket_readUint16(sfPacket* packet)
{
    CSFML_CHECK_RETURN(packet, sfFalse);
    sfUint16 value;
    packet->This >> value;
    return value;
}
sfInt32 sfPacket_readInt32(sfPacket* packet)
{
    CSFML_CHECK_RETURN(packet, sfFalse);
    sfInt32 value;
    packet->This >> value;
    return value;
}
sfUint32 sfPacket_readUint32(sfPacket* packet)
{
    CSFML_CHECK_RETURN(packet, sfFalse);
    sfUint32 value;
    packet->This >> value;
    return value;
}
float sfPacket_readFloat(sfPacket* packet)
{
    CSFML_CHECK_RETURN(packet, sfFalse);
    float value;
    packet->This >> value;
    return value;
}
double sfPacket_readDouble(sfPacket* packet)
{
    CSFML_CHECK_RETURN(packet, sfFalse);
    double value;
    packet->This >> value;
    return value;
}
void sfPacket_readString(sfPacket* packet, char* string)
{
    CSFML_CHECK(packet);
    if (string)
        packet->This >> string;
}
void sfPacket_readWideString(sfPacket* packet, wchar_t* string)
{
    CSFML_CHECK(packet);
    if (string)
        packet->This >> string;
}


////////////////////////////////////////////////////////////
void sfPacket_writeBool(sfPacket* packet, sfBool value)
{
    sfPacket_writeUint8(packet, value ? 1 : 0);
}
void sfPacket_writeInt8(sfPacket* packet, sfInt8 value)
{
    CSFML_CHECK(packet);
    packet->This << value;
}
void sfPacket_writeUint8(sfPacket* packet, sfUint8 value)
{
    CSFML_CHECK(packet);
    packet->This << value;
}
void sfPacket_writeInt16(sfPacket* packet, sfInt16 value)
{
    CSFML_CHECK(packet);
    packet->This << value;
}
void sfPacket_writeUint16(sfPacket* packet, sfUint16 value)
{
    CSFML_CHECK(packet);
    packet->This << value;
}
void sfPacket_writeInt32(sfPacket* packet, sfInt32 value)
{
    CSFML_CHECK(packet);
    packet->This << value;
}
void sfPacket_writeUint32(sfPacket* packet, sfUint32 value)
{
    CSFML_CHECK(packet);
    packet->This << value;
}
void sfPacket_writeFloat(sfPacket* packet, float value)
{
    CSFML_CHECK(packet);
    packet->This << value;
}
void sfPacket_writeDouble(sfPacket* packet, double value)
{
    CSFML_CHECK(packet);
    packet->This << value;
}
void sfPacket_writeString(sfPacket* packet, const char* string)
{
    CSFML_CHECK(packet);

    if (string)
        packet->This << string;
}
void sfPacket_writeWideString(sfPacket* packet, const wchar_t* string)
{
    CSFML_CHECK(packet);

    if (string)
        packet->This << string;
}
