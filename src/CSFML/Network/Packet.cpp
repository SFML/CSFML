////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2024 Laurent Gomila (laurent@sfml-dev.org)
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
#include <CSFML/Network/Packet.h>
#include <CSFML/Network/PacketStruct.hpp>

#include <cassert>


////////////////////////////////////////////////////////////
sfPacket* sfPacket_create()
{
    return new sfPacket;
}


////////////////////////////////////////////////////////////
sfPacket* sfPacket_copy(const sfPacket* packet)
{
    assert(packet);
    return new sfPacket(*packet);
}


////////////////////////////////////////////////////////////
void sfPacket_destroy(const sfPacket* packet)
{
    delete packet;
}


////////////////////////////////////////////////////////////
void sfPacket_append(sfPacket* packet, const void* data, size_t sizeInBytes)
{
    assert(packet);
    packet->append(data, sizeInBytes);
}


////////////////////////////////////////////////////////////
size_t sfPacket_getReadPosition(const sfPacket* packet)
{
    assert(packet);
    return packet->getReadPosition();
}


////////////////////////////////////////////////////////////
void sfPacket_clear(sfPacket* packet)
{
    assert(packet);
    packet->clear();
}


////////////////////////////////////////////////////////////
const void* sfPacket_getData(const sfPacket* packet)
{
    assert(packet);
    return packet->getData();
}


////////////////////////////////////////////////////////////
size_t sfPacket_getDataSize(const sfPacket* packet)
{
    assert(packet);
    return packet->getDataSize();
}


////////////////////////////////////////////////////////////
bool sfPacket_endOfPacket(const sfPacket* packet)
{
    assert(packet);
    return packet->endOfPacket();
}


////////////////////////////////////////////////////////////
bool sfPacket_canRead(const sfPacket* packet)
{
    assert(packet);
    return bool{*packet};
}


////////////////////////////////////////////////////////////
bool sfPacket_readBool(sfPacket* packet)
{
    return sfPacket_readUint8(packet);
}
int8_t sfPacket_readInt8(sfPacket* packet)
{
    assert(packet);
    int8_t value = 0;
    *packet >> value;
    return value;
}
uint8_t sfPacket_readUint8(sfPacket* packet)
{
    assert(packet);
    uint8_t value = 0;
    *packet >> value;
    return value;
}
int16_t sfPacket_readInt16(sfPacket* packet)
{
    assert(packet);
    int16_t value = 0;
    *packet >> value;
    return value;
}
uint16_t sfPacket_readUint16(sfPacket* packet)
{
    assert(packet);
    uint16_t value = 0;
    *packet >> value;
    return value;
}
int32_t sfPacket_readInt32(sfPacket* packet)
{
    assert(packet);
    int32_t value = 0;
    *packet >> value;
    return value;
}
uint32_t sfPacket_readUint32(sfPacket* packet)
{
    assert(packet);
    uint32_t value = 0;
    *packet >> value;
    return value;
}
int64_t sfPacket_readInt64(sfPacket* packet)
{
    assert(packet);
    int64_t value = 0;
    *packet >> value;
    return value;
}
uint64_t sfPacket_readUint64(sfPacket* packet)
{
    assert(packet);
    uint64_t value = 0;
    *packet >> value;
    return value;
}
float sfPacket_readFloat(sfPacket* packet)
{
    assert(packet);
    float value = 0;
    *packet >> value;
    return value;
}
double sfPacket_readDouble(sfPacket* packet)
{
    assert(packet);
    double value = 0;
    *packet >> value;
    return value;
}
void sfPacket_readString(sfPacket* packet, char* string)
{
    assert(packet);
    if (string)
        *packet >> string;
}
void sfPacket_readWideString(sfPacket* packet, wchar_t* string)
{
    assert(packet);
    if (string)
        *packet >> string;
}


////////////////////////////////////////////////////////////
void sfPacket_writeBool(sfPacket* packet, bool value)
{
    sfPacket_writeUint8(packet, value ? 1 : 0);
}
void sfPacket_writeInt8(sfPacket* packet, int8_t value)
{
    assert(packet);
    *packet << value;
}
void sfPacket_writeUint8(sfPacket* packet, uint8_t value)
{
    assert(packet);
    *packet << value;
}
void sfPacket_writeInt16(sfPacket* packet, int16_t value)
{
    assert(packet);
    *packet << value;
}
void sfPacket_writeUint16(sfPacket* packet, uint16_t value)
{
    assert(packet);
    *packet << value;
}
void sfPacket_writeInt32(sfPacket* packet, int32_t value)
{
    assert(packet);
    *packet << value;
}
void sfPacket_writeUint32(sfPacket* packet, uint32_t value)
{
    assert(packet);
    *packet << value;
}
void sfPacket_writeInt64(sfPacket* packet, int64_t value)
{
    assert(packet);
    *packet << value;
}
void sfPacket_writeUint64(sfPacket* packet, uint64_t value)
{
    assert(packet);
    *packet << value;
}
void sfPacket_writeFloat(sfPacket* packet, float value)
{
    assert(packet);
    *packet << value;
}
void sfPacket_writeDouble(sfPacket* packet, double value)
{
    assert(packet);
    *packet << value;
}
void sfPacket_writeString(sfPacket* packet, const char* string)
{
    assert(packet);
    if (string)
        *packet << string;
}
void sfPacket_writeWideString(sfPacket* packet, const wchar_t* string)
{
    assert(packet);
    if (string)
        *packet << string;
}
