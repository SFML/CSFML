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

#ifndef SFML_MUTEX_H
#define SFML_MUTEX_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Config.h>
#include <SFML/System/Types.h>


////////////////////////////////////////////////////////////
/// \brief Create a new mutex
///
/// \return A new sfMutex object
///
////////////////////////////////////////////////////////////
CSFML_API sfMutex* sfMutex_Create(void);

////////////////////////////////////////////////////////////
/// \brief Destroy a mutex
///
/// \param mutex Mutex to destroy
///
////////////////////////////////////////////////////////////
CSFML_API void sfMutex_Destroy(sfMutex* mutex);

////////////////////////////////////////////////////////////
/// \brief Lock a mutex
///
/// \param mutex Mutex object
///
////////////////////////////////////////////////////////////
CSFML_API void sfMutex_Lock(sfMutex* mutex);

////////////////////////////////////////////////////////////
/// \brief Unlock a mutex
///
/// \param mutex Mutex object
///
////////////////////////////////////////////////////////////
CSFML_API void sfMutex_Unlock(sfMutex* mutex);


#endif // SFML_MUTEX_H
