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

#ifndef SFML_KEYBOARD_H
#define SFML_KEYBOARD_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Window/Export.h>


////////////////////////////////////////////////////////////
/// \brief Key codes
///
/// The enumerators refer to the "localized" key; i.e. depending
/// on the layout set by the operating system, a key can be mapped
/// to `Y` or `Z`.
///
////////////////////////////////////////////////////////////
typedef enum
{
    sfKeyUnknown = -1, ///< Unhandled key
    sfKeyA,            ///< The A key
    sfKeyB,            ///< The B key
    sfKeyC,            ///< The C key
    sfKeyD,            ///< The D key
    sfKeyE,            ///< The E key
    sfKeyF,            ///< The F key
    sfKeyG,            ///< The G key
    sfKeyH,            ///< The H key
    sfKeyI,            ///< The I key
    sfKeyJ,            ///< The J key
    sfKeyK,            ///< The K key
    sfKeyL,            ///< The L key
    sfKeyM,            ///< The M key
    sfKeyN,            ///< The N key
    sfKeyO,            ///< The O key
    sfKeyP,            ///< The P key
    sfKeyQ,            ///< The Q key
    sfKeyR,            ///< The R key
    sfKeyS,            ///< The S key
    sfKeyT,            ///< The T key
    sfKeyU,            ///< The U key
    sfKeyV,            ///< The V key
    sfKeyW,            ///< The W key
    sfKeyX,            ///< The X key
    sfKeyY,            ///< The Y key
    sfKeyZ,            ///< The Z key
    sfKeyNum0,         ///< The 0 key
    sfKeyNum1,         ///< The 1 key
    sfKeyNum2,         ///< The 2 key
    sfKeyNum3,         ///< The 3 key
    sfKeyNum4,         ///< The 4 key
    sfKeyNum5,         ///< The 5 key
    sfKeyNum6,         ///< The 6 key
    sfKeyNum7,         ///< The 7 key
    sfKeyNum8,         ///< The 8 key
    sfKeyNum9,         ///< The 9 key
    sfKeyEscape,       ///< The Escape key
    sfKeyLControl,     ///< The left Control key
    sfKeyLShift,       ///< The left Shift key
    sfKeyLAlt,         ///< The left Alt key
    sfKeyLSystem,      ///< The left OS specific key: window (Windows and Linux), apple (macOS), ...
    sfKeyRControl,     ///< The right Control key
    sfKeyRShift,       ///< The right Shift key
    sfKeyRAlt,         ///< The right Alt key
    sfKeyRSystem,      ///< The right OS specific key: window (Windows and Linux), apple (macOS), ...
    sfKeyMenu,         ///< The Menu key
    sfKeyLBracket,     ///< The [ key
    sfKeyRBracket,     ///< The ] key
    sfKeySemicolon,    ///< The ; key
    sfKeyComma,        ///< The , key
    sfKeyPeriod,       ///< The . key
    sfKeyApostrophe,   ///< The ' key
    sfKeySlash,        ///< The / key
    sfKeyBackslash,    ///< The \ key
    sfKeyGrave,        ///< The ` key
    sfKeyEqual,        ///< The = key
    sfKeyHyphen,       ///< The - key (hyphen)
    sfKeySpace,        ///< The Space key
    sfKeyEnter,        ///< The Enter/Return key
    sfKeyBackspace,    ///< The Backspace key
    sfKeyTab,          ///< The Tabulation key
    sfKeyPageUp,       ///< The Page up key
    sfKeyPageDown,     ///< The Page down key
    sfKeyEnd,          ///< The End key
    sfKeyHome,         ///< The Home key
    sfKeyInsert,       ///< The Insert key
    sfKeyDelete,       ///< The Delete key
    sfKeyAdd,          ///< The + key
    sfKeySubtract,     ///< The - key (minus, usually from numpad)
    sfKeyMultiply,     ///< The * key
    sfKeyDivide,       ///< The / key
    sfKeyLeft,         ///< Left arrow
    sfKeyRight,        ///< Right arrow
    sfKeyUp,           ///< Up arrow
    sfKeyDown,         ///< Down arrow
    sfKeyNumpad0,      ///< The numpad 0 key
    sfKeyNumpad1,      ///< The numpad 1 key
    sfKeyNumpad2,      ///< The numpad 2 key
    sfKeyNumpad3,      ///< The numpad 3 key
    sfKeyNumpad4,      ///< The numpad 4 key
    sfKeyNumpad5,      ///< The numpad 5 key
    sfKeyNumpad6,      ///< The numpad 6 key
    sfKeyNumpad7,      ///< The numpad 7 key
    sfKeyNumpad8,      ///< The numpad 8 key
    sfKeyNumpad9,      ///< The numpad 9 key
    sfKeyF1,           ///< The F1 key
    sfKeyF2,           ///< The F2 key
    sfKeyF3,           ///< The F3 key
    sfKeyF4,           ///< The F4 key
    sfKeyF5,           ///< The F5 key
    sfKeyF6,           ///< The F6 key
    sfKeyF7,           ///< The F7 key
    sfKeyF8,           ///< The F8 key
    sfKeyF9,           ///< The F8 key
    sfKeyF10,          ///< The F10 key
    sfKeyF11,          ///< The F11 key
    sfKeyF12,          ///< The F12 key
    sfKeyF13,          ///< The F13 key
    sfKeyF14,          ///< The F14 key
    sfKeyF15,          ///< The F15 key
    sfKeyPause,        ///< The Pause key

    sfKeyCount,      ///< Keep last -- the total number of keyboard keys

    // Deprecated values:

    sfKeyTilde     = sfKeyGrave,     ///< \deprecated Use Grave instead
    sfKeyDash      = sfKeyHyphen,    ///< \deprecated Use Hyphen instead
    sfKeyBack      = sfKeyBackspace, ///< \deprecated Use Backspace instead
    sfKeyBackSlash = sfKeyBackslash, ///< \deprecated Use Backslash instead
    sfKeySemiColon = sfKeySemicolon, ///< \deprecated Use Semicolon instead
    sfKeyReturn    = sfKeyEnter,     ///< \deprecated Use Enter instead
    sfKeyQuote     = sfKeyApostrophe ///< \deprecated Use Apostrophe instead
} sfKeyCode;


////////////////////////////////////////////////////////////
/// \brief Scancodes
///
/// The enumerators are bound to a physical key and do not depend on
/// the keyboard layout used by the operating system. Usually, the AT-101
/// keyboard can be used as reference for the physical position of the keys.
///
////////////////////////////////////////////////////////////
typedef enum
{
    sfScanUnknown = -1,       //!< Represents any scancode not present in this enum
    sfScanA = 0,              //!< Keyboard a and A key
    sfScanB,                  //!< Keyboard b and B key
    sfScanC,                  //!< Keyboard c and C key
    sfScanD,                  //!< Keyboard d and D key
    sfScanE,                  //!< Keyboard e and E key
    sfScanF,                  //!< Keyboard f and F key
    sfScanG,                  //!< Keyboard g and G key
    sfScanH,                  //!< Keyboard h and H key
    sfScanI,                  //!< Keyboard i and I key
    sfScanJ,                  //!< Keyboard j and J key
    sfScanK,                  //!< Keyboard k and K key
    sfScanL,                  //!< Keyboard l and L key
    sfScanM,                  //!< Keyboard m and M key
    sfScanN,                  //!< Keyboard n and N key
    sfScanO,                  //!< Keyboard o and O key
    sfScanP,                  //!< Keyboard p and P key
    sfScanQ,                  //!< Keyboard q and Q key
    sfScanR,                  //!< Keyboard r and R key
    sfScanS,                  //!< Keyboard s and S key
    sfScanT,                  //!< Keyboard t and T key
    sfScanU,                  //!< Keyboard u and U key
    sfScanV,                  //!< Keyboard v and V key
    sfScanW,                  //!< Keyboard w and W key
    sfScanX,                  //!< Keyboard x and X key
    sfScanY,                  //!< Keyboard y and Y key
    sfScanZ,                  //!< Keyboard z and Z key
    sfScanNum1,               //!< Keyboard 1 and ! key
    sfScanNum2,               //!< Keyboard 2 and @ key
    sfScanNum3,               //!< Keyboard 3 and # key
    sfScanNum4,               //!< Keyboard 4 and $ key
    sfScanNum5,               //!< Keyboard 5 and % key
    sfScanNum6,               //!< Keyboard 6 and ^ key
    sfScanNum7,               //!< Keyboard 7 and & key
    sfScanNum8,               //!< Keyboard 8 and * key
    sfScanNum9,               //!< Keyboard 9 and ) key
    sfScanNum0,               //!< Keyboard 0 and ) key
    sfScanEnter,              //!< Keyboard Enter/Return key
    sfScanEscape,             //!< Keyboard Escape key
    sfScanBackspace,          //!< Keyboard Backspace key
    sfScanTab,                //!< Keyboard Tab key
    sfScanSpace,              //!< Keyboard Space key
    sfScanHyphen,             //!< Keyboard - and _ key
    sfScanEqual,              //!< Keyboard = and +
    sfScanLBracket,           //!< Keyboard [ and { key
    sfScanRBracket,           //!< Keyboard ] and } key
    // For US keyboards mapped to key 29 (Microsoft Keyboard Scan Code Specification)
    // For Non-US keyboards mapped to key 42 (Microsoft Keyboard Scan Code Specification)
    // Typical language mappings: Belg:£µ` FrCa:<>} Dan:*' Dutch:`´ Fren:µ* Ger:'# Ital:§ù LatAm:[}` Nor:*@ Span:ç} Swed:*' Swiss:$£} UK:~# Brazil:}]
    sfScanBackslash,          //!< Keyboard \ and | key OR various keys for Non-US keyboards
    sfScanSemicolon,          //!< Keyboard ; and : key
    sfScanApostrophe,         //!< Keyboard ' and " key
    sfScanGrave,              //!< Keyboard ` and ~ key
    sfScanComma,              //!< Keyboard , and < key
    sfScanPeriod,             //!< Keyboard . and > key
    sfScanSlash,              //!< Keyboard / and ? key
    sfScanF1,                 //!< Keyboard F1 key
    sfScanF2,                 //!< Keyboard F2 key
    sfScanF3,                 //!< Keyboard F3 key
    sfScanF4,                 //!< Keyboard F4 key
    sfScanF5,                 //!< Keyboard F5 key
    sfScanF6,                 //!< Keyboard F6 key
    sfScanF7,                 //!< Keyboard F7 key
    sfScanF8,                 //!< Keyboard F8 key
    sfScanF9,                 //!< Keyboard F9 key
    sfScanF10,                //!< Keyboard F10 key
    sfScanF11,                //!< Keyboard F11 key
    sfScanF12,                //!< Keyboard F12 key
    sfScanF13,                //!< Keyboard F13 key
    sfScanF14,                //!< Keyboard F14 key
    sfScanF15,                //!< Keyboard F15 key
    sfScanF16,                //!< Keyboard F16 key
    sfScanF17,                //!< Keyboard F17 key
    sfScanF18,                //!< Keyboard F18 key
    sfScanF19,                //!< Keyboard F19 key
    sfScanF20,                //!< Keyboard F20 key
    sfScanF21,                //!< Keyboard F21 key
    sfScanF22,                //!< Keyboard F22 key
    sfScanF23,                //!< Keyboard F23 key
    sfScanF24,                //!< Keyboard F24 key
    sfScanCapsLock,           //!< Keyboard Caps %Lock key
    sfScanPrintScreen,        //!< Keyboard Print Screen key
    sfScanScrollLock,         //!< Keyboard Scroll %Lock key
    sfScanPause,              //!< Keyboard Pause key
    sfScanInsert,             //!< Keyboard Insert key
    sfScanHome,               //!< Keyboard Home key
    sfScanPageUp,             //!< Keyboard Page Up key
    sfScanDelete,             //!< Keyboard Delete Forward key
    sfScanEnd,                //!< Keyboard End key
    sfScanPageDown,           //!< Keyboard Page Down key
    sfScanRight,              //!< Keyboard Right Arrow key
    sfScanLeft,               //!< Keyboard Left Arrow key
    sfScanDown,               //!< Keyboard Down Arrow key
    sfScanUp,                 //!< Keyboard Up Arrow key
    sfScanNumLock,            //!< Keypad Num %Lock and Clear key
    sfScanNumpadDivide,       //!< Keypad / key
    sfScanNumpadMultiply,     //!< Keypad * key
    sfScanNumpadMinus,        //!< Keypad - key
    sfScanNumpadPlus,         //!< Keypad + key
    sfScanNumpadEqual,        //!< keypad = key
    sfScanNumpadEnter,        //!< Keypad Enter/Return key
    sfScanNumpadDecimal,      //!< Keypad . and Delete key
    sfScanNumpad1,            //!< Keypad 1 and End key
    sfScanNumpad2,            //!< Keypad 2 and Down Arrow key
    sfScanNumpad3,            //!< Keypad 3 and Page Down key
    sfScanNumpad4,            //!< Keypad 4 and Left Arrow key
    sfScanNumpad5,            //!< Keypad 5 key
    sfScanNumpad6,            //!< Keypad 6 and Right Arrow key
    sfScanNumpad7,            //!< Keypad 7 and Home key
    sfScanNumpad8,            //!< Keypad 8 and Up Arrow key
    sfScanNumpad9,            //!< Keypad 9 and Page Up key
    sfScanNumpad0,            //!< Keypad 0 and Insert key
    // For US keyboards doesn't exist
    // For Non-US keyboards mapped to key 45 (Microsoft Keyboard Scan Code Specification)
    // Typical language mappings: Belg:<\> FrCa:«°» Dan:<\> Dutch:]|[ Fren:<> Ger:<|> Ital:<> LatAm:<> Nor:<> Span:<> Swed:<|> Swiss:<\> UK:\| Brazil: \|.
    sfScanNonUsBackslash,     //!< Keyboard Non-US \ and | key
    sfScanApplication,        //!< Keyboard Application key
    sfScanExecute,            //!< Keyboard Execute key
    sfScanModeChange,         //!< Keyboard Mode Change key
    sfScanHelp,               //!< Keyboard Help key
    sfScanMenu,               //!< Keyboard Menu key
    sfScanSelect,             //!< Keyboard Select key
    sfScanRedo,               //!< Keyboard Redo key
    sfScanUndo,               //!< Keyboard Undo key
    sfScanCut,                //!< Keyboard Cut key
    sfScanCopy,               //!< Keyboard Copy key
    sfScanPaste,              //!< Keyboard Paste key
    sfScanVolumeMute,         //!< Keyboard Volume Mute key
    sfScanVolumeUp,           //!< Keyboard Volume Up key
    sfScanVolumeDown,         //!< Keyboard Volume Down key
    sfScanMediaPlayPause,     //!< Keyboard Media Play Pause key
    sfScanMediaStop,          //!< Keyboard Media Stop key
    sfScanMediaNextTrack,     //!< Keyboard Media Next Track key
    sfScanMediaPreviousTrack, //!< Keyboard Media Previous Track key
    sfScanLControl,           //!< Keyboard Left Control key
    sfScanLShift,             //!< Keyboard Left Shift key
    sfScanLAlt,               //!< Keyboard Left Alt key
    sfScanLSystem,            //!< Keyboard Left System key
    sfScanRControl,           //!< Keyboard Right Control key
    sfScanRShift,             //!< Keyboard Right Shift key
    sfScanRAlt,               //!< Keyboard Right Alt key
    sfScanRSystem,            //!< Keyboard Right System key
    sfScanBack,               //!< Keyboard Back key
    sfScanForward,            //!< Keyboard Forward key
    sfScanRefresh,            //!< Keyboard Refresh key
    sfScanStop,               //!< Keyboard Stop key
    sfScanSearch,             //!< Keyboard Search key
    sfScanFavorites,          //!< Keyboard Favorites key
    sfScanHomePage,           //!< Keyboard Home Page key
    sfScanLaunchApplication1, //!< Keyboard Launch Application 1 key
    sfScanLaunchApplication2, //!< Keyboard Launch Application 2 key
    sfScanLaunchMail,         //!< Keyboard Launch Mail key
    sfScanLaunchMediaSelect,  //!< Keyboard Launch Media Select key

    sfScancodeCount           //!< Keep last -- the total number of scancodes
} sfScancode;


////////////////////////////////////////////////////////////
/// \brief Check if a key is pressed
///
/// \param key Key to check
///
/// \return sfTrue if the key is pressed, sfFalse otherwise
///
/// \see sfKeyboard_isScancodePressed
///
////////////////////////////////////////////////////////////
CSFML_WINDOW_API sfBool sfKeyboard_isKeyPressed(sfKeyCode key);

////////////////////////////////////////////////////////////
/// \brief Check if a key is pressed
///
/// \param code Scancode to check
///
/// \return sfTrue if the physical key is pressed, sfFalse otherwise
///
/// \see sfKeyboard_isKeyPressed
///
////////////////////////////////////////////////////////////
CSFML_WINDOW_API sfBool sfKeyboard_isScancodePressed(sfScancode code);

////////////////////////////////////////////////////////////
/// \brief Localize a physical key to a logical one
///
/// \param code Scancode to localize
///
/// \return The key corresponding to the scancode under the current
///         keyboard layout used by the operating system, or
///         sfKeyUnknown when the scancode cannot be mapped
///         to a Key.
///
/// \see sfKeyboard_delocalize
///
////////////////////////////////////////////////////////////
CSFML_WINDOW_API sfKeyCode sfKeyboard_localize(sfScancode code);

////////////////////////////////////////////////////////////
/// \brief Identify the physical key corresponding to a logical one
///
/// \param key Key to "delocalize"
///
/// \return The scancode corresponding to the key under the current
///         keyboard layout used by the operating system, or
///         sfScanUnknown when the key cannot be mapped
///         to a sfScancode.
///
/// \see sfKeyboard_localize
///
////////////////////////////////////////////////////////////
CSFML_WINDOW_API sfScancode sfKeyboard_delocalize(sfKeyCode key);

////////////////////////////////////////////////////////////
/// \brief Provide a string representation for a given scancode
///
/// The returned string is a short, non-technical description of
/// the key represented with the given scancode. Most effectively
/// used in user interfaces, as the description for the key takes
/// the users keyboard layout into consideration.
///
/// \warning The result is OS-dependent: for example, sfScanLSystem
///          is "Left Meta" on Linux, "Left Windows" on Windows and
///          "Left Command" on macOS.
///
/// The current keyboard layout set by the operating system is used to
/// interpret the scancode: for example, sfKeySemicolon is
/// mapped to ";" for layout and to "é" for others.
///
/// The returned const char* owns the string and must be freed to
/// avoid memory leaks.
///
/// \param code Scancode to describe
///
/// \return The localized description of the code
///
////////////////////////////////////////////////////////////
CSFML_WINDOW_API const char* sfKeyboard_getDescription(sfScancode code);

////////////////////////////////////////////////////////////
/// \brief Show or hide the virtual keyboard.
///
/// \warning The virtual keyboard is not supported on all
///          systems. It will typically be implemented on mobile OSes
///          (Android, iOS) but not on desktop OSes (Windows, Linux, ...).
///
/// If the virtual keyboard is not available, this function does nothing.
///
/// \param visible True to show, false to hide
///
////////////////////////////////////////////////////////////
CSFML_WINDOW_API void sfKeyboard_setVirtualKeyboardVisible(sfBool visible);

#endif // SFML_KEYBOARD_H
