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

#ifndef SFML_PACKET_H
#define SFML_PACKET_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Network/Export.h>
#include <SFML/Network/Types.h>
#include <stddef.h>


////////////////////////////////////////////////////////////
/// \brief Create a new packet
///
/// \return A new sfPacket object
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfPacket* sfPacket_Create(void);

////////////////////////////////////////////////////////////
/// \brief Create a new packet by copying an existing one
///
/// \param packet Packet to copy
///
/// \return A new sfPacket object which is a copy of \a packet
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfPacket* sfPacket_Copy(sfPacket* packet);

////////////////////////////////////////////////////////////
/// \brief Destroy a packet
///
/// \param packet Packet to destroy
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API void sfPacket_Destroy(sfPacket* packet);

////////////////////////////////////////////////////////////
/// \brief Append data to the end of a packet
///
/// \param packet      Packet object
/// \param data        Pointer to the sequence of bytes to append
/// \param sizeInBytes Number of bytes to append
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API void sfPacket_Append(sfPacket* packet, const void* data, size_t sizeInBytes);

////////////////////////////////////////////////////////////
/// \brief Clear a packet
///
/// After calling Clear, the packet is empty.
///
/// \param packet Packet object
///
///////////////////////////////////////////////////////////
CSFML_NETWORK_API void sfPacket_Clear(sfPacket* packet);

////////////////////////////////////////////////////////////
/// \brief Get a pointer to the data contained in a packet
///
/// Warning: the returned pointer may become invalid after
/// you append data to the packet, therefore it should never
/// be stored.
/// The return pointer is NULL if the packet is empty.
///
/// \param packet Packet object
///
/// \return Pointer to the data
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API const char* sfPacket_GetData(const sfPacket* packet);

////////////////////////////////////////////////////////////
/// \brief Get the size of the data contained in a packet
///
/// This function returns the number of bytes pointed to by
/// what sfPacket_GetData returns.
///
/// \param packet Packet object
///
/// \return Data size, in bytes
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API size_t sfPacket_GetDataSize(const sfPacket* packet);

////////////////////////////////////////////////////////////
/// \brief Tell if the reading position has reached the
///        end of a packet
///
/// This function is useful to know if there is some data
/// left to be read, without actually reading it.
///
/// \param packet Packet object
///
/// \return sfTrue if all data was read, sfFalse otherwise
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfBool sfPacket_EndOfPacket(const sfPacket* packet);

////////////////////////////////////////////////////////////
/// \brief Test the validity of a packet, for reading
///
/// This function allows to test the packet, to check if
/// a reading operation was successful.
///
/// A packet will be in an invalid state if it has no more
/// data to read.
///
/// \param packet Packet object
///
/// \return sfTrue if last data extraction from packet was successful
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfBool sfPacket_CanRead(const sfPacket* packet);

////////////////////////////////////////////////////////////
/// \brief Functions to extract data from a packet
///
/// \param packet Packet object
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfBool   sfPacket_ReadBool(sfPacket* packet);
CSFML_NETWORK_API sfInt8   sfPacket_ReadInt8(sfPacket* packet);
CSFML_NETWORK_API sfUint8  sfPacket_ReadUint8(sfPacket* packet);
CSFML_NETWORK_API sfInt16  sfPacket_ReadInt16(sfPacket* packet);
CSFML_NETWORK_API sfUint16 sfPacket_ReadUint16(sfPacket* packet);
CSFML_NETWORK_API sfInt32  sfPacket_ReadInt32(sfPacket* packet);
CSFML_NETWORK_API sfUint32 sfPacket_ReadUint32(sfPacket* packet);
CSFML_NETWORK_API float    sfPacket_ReadFloat(sfPacket* packet);
CSFML_NETWORK_API double   sfPacket_ReadDouble(sfPacket* packet);
CSFML_NETWORK_API void     sfPacket_ReadString(sfPacket* packet, char* string);
CSFML_NETWORK_API void     sfPacket_ReadWideString(sfPacket* packet, wchar_t* string);

////////////////////////////////////////////////////////////
/// \brief Functions to insert data into a packet
///
/// \param packet Packet object
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API void sfPacket_WriteBool(sfPacket* packet, sfBool);
CSFML_NETWORK_API void sfPacket_WriteInt8(sfPacket* packet, sfInt8);
CSFML_NETWORK_API void sfPacket_WriteUint8(sfPacket* packet, sfUint8);
CSFML_NETWORK_API void sfPacket_WriteInt16(sfPacket* packet, sfInt16);
CSFML_NETWORK_API void sfPacket_WriteUint16(sfPacket* packet, sfUint16);
CSFML_NETWORK_API void sfPacket_WriteInt32(sfPacket* packet, sfInt32);
CSFML_NETWORK_API void sfPacket_WriteUint32(sfPacket* packet, sfUint32);
CSFML_NETWORK_API void sfPacket_WriteFloat(sfPacket* packet, float);
CSFML_NETWORK_API void sfPacket_WriteDouble(sfPacket* packet, double);
CSFML_NETWORK_API void sfPacket_WriteString(sfPacket* packet, const char* string);
CSFML_NETWORK_API void sfPacket_WriteWideString(sfPacket* packet, const wchar_t* string);


#endif // SFML_PACKET_H
