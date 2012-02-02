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
#include <SFML/System/Time.h>


////////////////////////////////////////////////////////////
sfTime sfTimeZero = {0};


////////////////////////////////////////////////////////////
float sfTime_AsSeconds(sfTime time)
{
    return time.Microseconds / 1000000.f;
}


////////////////////////////////////////////////////////////
sfInt32 sfTime_AsMilliseconds(sfTime time)
{
    return static_cast<sfUint32>(time.Microseconds / 1000);
}


////////////////////////////////////////////////////////////
sfInt64 sfTime_AsMicroseconds(sfTime time)
{
    return time.Microseconds;
}


////////////////////////////////////////////////////////////
sfTime sfSeconds(float amount)
{
    sfTime time;
    time.Microseconds = static_cast<sfUint64>(amount * 1000000);
    return time;
}


////////////////////////////////////////////////////////////
sfTime sfMilliseconds(sfInt32 amount)
{
    sfTime time;
    time.Microseconds = static_cast<sfUint64>(amount) * 1000;
    return time;
}


////////////////////////////////////////////////////////////
sfTime sfMicroseconds(sfInt64 amount)
{
    sfTime time;
    time.Microseconds = amount;
    return time;
}
