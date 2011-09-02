////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2009 Laurent Gomila (laurent.gom@gmail.com)
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


namespace
{
    // Helper function to read a variable from a packet
    template <typename T>
    T PacketRead(sfPacket* packet)
    {
        CSFML_CHECK_RETURN(packet, 0);

        T value;
        packet->This >> value;
        return value;
    }

    // Helper function to write a variable to a packet
    template <typename T>
    void PacketWrite(sfPacket* packet, T value)
    {
        CSFML_CHECK(packet);

        packet->This << value;
    }
}


////////////////////////////////////////////////////////////
sfPacket* sfPacket_Create(void)
{
    return new sfPacket;
}


////////////////////////////////////////////////////////////
sfPacket* sfPacket_Copy(sfPacket* packet)
{
    CSFML_CHECK_RETURN(packet, NULL);

    return new sfPacket(*packet);
}


////////////////////////////////////////////////////////////
void sfPacket_Destroy(sfPacket* packet)
{
    delete packet;
}


////////////////////////////////////////////////////////////
void sfPacket_Append(sfPacket* packet, const void* data, size_t sizeInBytes)
{
    CSFML_CALL(packet, Append(data, sizeInBytes));
}


////////////////////////////////////////////////////////////
void sfPacket_Clear(sfPacket* packet)
{
    CSFML_CALL(packet, Clear());
}


////////////////////////////////////////////////////////////
const char* sfPacket_GetData(const sfPacket* packet)
{
    CSFML_CALL_RETURN(packet, GetData(), NULL);
}


////////////////////////////////////////////////////////////
size_t sfPacket_GetDataSize(const sfPacket* packet)
{
    CSFML_CALL_RETURN(packet, GetDataSize(), 0);
}


////////////////////////////////////////////////////////////
sfBool sfPacket_EndOfPacket(const sfPacket* packet)
{
    CSFML_CALL_RETURN(packet, EndOfPacket(), sfFalse);
}


////////////////////////////////////////////////////////////
sfBool sfPacket_CanRead(const sfPacket* packet)
{
    CSFML_CHECK_RETURN(packet, sfFalse);
    return packet->This ? sfTrue : sfFalse;
}


////////////////////////////////////////////////////////////
sfBool   sfPacket_ReadBool(sfPacket* packet)   {return PacketRead<sfUint8>(packet);}
sfInt8   sfPacket_ReadInt8(sfPacket* packet)   {return PacketRead<sfInt8>(packet);}
sfUint8  sfPacket_ReadUint8(sfPacket* packet)  {return PacketRead<sfUint8>(packet);}
sfInt16  sfPacket_ReadInt16(sfPacket* packet)  {return PacketRead<sfInt16>(packet);}
sfUint16 sfPacket_ReadUint16(sfPacket* packet) {return PacketRead<sfUint16>(packet);}
sfInt32  sfPacket_ReadInt32(sfPacket* packet)  {return PacketRead<sfInt32>(packet);}
sfUint32 sfPacket_ReadUint32(sfPacket* packet) {return PacketRead<sfUint32>(packet);}
float    sfPacket_ReadFloat(sfPacket* packet)  {return PacketRead<float>(packet);}
double   sfPacket_ReadDouble(sfPacket* packet) {return PacketRead<double>(packet);}

void sfPacket_ReadString(sfPacket* packet, char* string)
{
    CSFML_CHECK(packet);

    if (string)
        packet->This >> string;
}

void sfPacket_ReadWideString(sfPacket* packet, wchar_t* string)
{
    CSFML_CHECK(packet);

    if (string)
        packet->This >> string;
}


////////////////////////////////////////////////////////////
void sfPacket_WriteBool(sfPacket* packet,   sfBool value)      {PacketWrite(packet, static_cast<sfUint8>(value));}
void sfPacket_WriteInt8(sfPacket* packet,   sfInt8 value)      {PacketWrite(packet, value);}
void sfPacket_WriteUint8(sfPacket* packet,  sfUint8 value)     {PacketWrite(packet, value);}
void sfPacket_WriteInt16(sfPacket* packet,  sfInt16 value)     {PacketWrite(packet, value);}
void sfPacket_WriteUint16(sfPacket* packet, sfUint16 value)    {PacketWrite(packet, value);}
void sfPacket_WriteInt32(sfPacket* packet,  sfInt32 value)     {PacketWrite(packet, value);}
void sfPacket_WriteUint32(sfPacket* packet, sfUint32 value)    {PacketWrite(packet, value);}
void sfPacket_WriteFloat(sfPacket* packet,  float value)       {PacketWrite(packet, value);}
void sfPacket_WriteDouble(sfPacket* packet, double value)      {PacketWrite(packet, value);}

void sfPacket_WriteString(sfPacket* packet, const char* string)
{
    CSFML_CHECK(packet);

    if (string)
        packet->This << string;
}

void sfPacket_WriteWideString(sfPacket* packet, const wchar_t* string)
{
    CSFML_CHECK(packet);

    if (string)
        packet->This << string;
}
