////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2026 Laurent Gomila (laurent@sfml-dev.org)
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

#pragma once

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <CSFML/Graphics/Export.h>

#include <CSFML/Graphics/Color.h>
#include <CSFML/Graphics/Glyph.h>
#include <CSFML/Graphics/Rect.h>
#include <CSFML/Graphics/Transform.h>
#include <CSFML/Graphics/Types.h>
#include <CSFML/Graphics/Vertex.h>
#include <CSFML/System/Vector2.h>

#include <stddef.h>
#include <stdint.h>


////////////////////////////////////////////////////////////
/// sfText styles
////////////////////////////////////////////////////////////
typedef enum
{
    sfTextRegular       = 0,      ///< Regular characters, no style
    sfTextBold          = 1 << 0, ///< Bold characters
    sfTextItalic        = 1 << 1, ///< Italic characters
    sfTextUnderlined    = 1 << 2, ///< Underlined characters
    sfTextStrikeThrough = 1 << 3  ///< Strike through characters
} sfTextStyle;

////////////////////////////////////////////////////////////
/// \brief Line alignment of a multi-line text
///
////////////////////////////////////////////////////////////
typedef enum
{
    sfTextLineAlignmentDefault, ///< Automatically align lines by script direction, left-align left-to-right text and right-align right-to-left text
    sfTextLineAlignmentLeft,   ///< Force align all lines to the left, regardless of script direction
    sfTextLineAlignmentCenter, ///< Force align all lines centrally
    sfTextLineAlignmentRight   ///< Force align lines to the right, regardless of script direction
} sfTextLineAlignment;

////////////////////////////////////////////////////////////
/// \brief Cluster grouping algorithm
///
////////////////////////////////////////////////////////////
typedef enum
{
    sfTextClusterGroupingGrapheme,  ///< Group clusters by grapheme
    sfTextClusterGroupingCharacter, ///< Group clusters by character
    sfTextClusterGroupingNone       ///< Do not group clusters
} sfTextClusterGrouping;

////////////////////////////////////////////////////////////
/// \brief Direction of the text a glyph belongs to
///
////////////////////////////////////////////////////////////
typedef enum
{
    sfTextDirectionUnspecified, ///< Unspecified
    sfTextDirectionLeftToRight, ///< Left-to-right
    sfTextDirectionRightToLeft, ///< Right-to-left
    sfTextDirectionTopToBottom, ///< Top-to-bottom
    sfTextDirectionBottomToTop  ///< Bottom-to-top
} sfTextDirection;

////////////////////////////////////////////////////////////
/// \brief Text orientation
///
////////////////////////////////////////////////////////////
typedef enum
{
    sfTextOrientationDefault,     ///< Default (left-to-right or right-to-left depending on detected script)
    sfTextOrientationTopToBottom, ///< Top-to-bottom
    sfTextOrientationBottomToTop  ///< Bottom-to-top
} sfTextOrientation;

////////////////////////////////////////////////////////////
/// \brief Glyph that has been positioned by the shaper
///
////////////////////////////////////////////////////////////
typedef struct
{
    sfGlyph         glyph;         ///< The glyph
    sfVector2f      position;      ///< Position of the glyph within a text
    uint32_t        cluster;       ///< Cluster ID
    sfTextDirection textDirection; ///< Text direction
    float           baseline;      ///< The baseline position of the line this glyph is a part of
    size_t          vertexOffset;  ///< Starting offset of the vertex data belonging to this glyph
    size_t          vertexCount;   ///< Count of vertices belonging to this glyph
} sfShapedGlyph;

////////////////////////////////////////////////////////////
/// \brief Callback that is provided with glyph data for pre-processing
///
/// The callback is called once per glyph whenever the text
/// geometry is regenerated, in the order in which the glyph
/// geometry is generated. The style, fill color, outline color
/// and outline thickness of the glyph can be modified through
/// the given pointers.
///
/// To map glyphs back to the input string, use the cluster
/// value of the shaped glyph. See sf::Text::GlyphPreProcessor
/// in the SFML documentation for a detailed explanation.
///
/// Changing the style or outline thickness might lead to
/// slight inconsistencies of the text bounds, changing the
/// fill or outline color is always safe. It is not safe to
/// query the text bounds from within the callback.
///
/// \param shapedGlyph      The shaped glyph to pre-process
/// \param style            Style of the glyph (see sfTextStyle enum)
/// \param fillColor        Fill color of the glyph
/// \param outlineColor     Outline color of the glyph
/// \param outlineThickness Outline thickness of the glyph
/// \param userData         User data passed to sfText_setGlyphPreProcessor
///
////////////////////////////////////////////////////////////
typedef void (*sfGlyphPreProcessor)(
    const sfShapedGlyph* shapedGlyph,
    uint32_t*            style,
    sfColor*             fillColor,
    sfColor*             outlineColor,
    float*               outlineThickness,
    void*                userData);


////////////////////////////////////////////////////////////
/// \brief Create a new text
///
/// \param font Font used to draw the string
///
/// \return A new sfText object, or NULL if it failed
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API sfText* sfText_create(const sfFont* font);

////////////////////////////////////////////////////////////
/// \brief Copy an existing text
///
/// \param text Text to copy
///
/// \return Copied object
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API sfText* sfText_copy(const sfText* text);

////////////////////////////////////////////////////////////
/// \brief Destroy an existing text
///
/// \param text Text to delete
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfText_destroy(const sfText* text);

////////////////////////////////////////////////////////////
/// \brief Set the position of a text
///
/// This function completely overwrites the previous position.
/// See sfText_move to apply an offset based on the previous position instead.
/// The default position of a text Text object is (0, 0).
///
/// \param text     Text object
/// \param position New position
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfText_setPosition(sfText* text, sfVector2f position);

////////////////////////////////////////////////////////////
/// \brief Set the orientation of a text
///
/// This function completely overwrites the previous rotation.
/// See sfText_rotate to add an angle based on the previous rotation instead.
/// The default rotation of a text Text object is 0.
///
/// \param text  Text object
/// \param angle New rotation, in degrees
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfText_setRotation(sfText* text, float angle);

////////////////////////////////////////////////////////////
/// \brief Set the scale factors of a text
///
/// This function completely overwrites the previous scale.
/// See sfText_scale to add a factor based on the previous scale instead.
/// The default scale of a text Text object is (1, 1).
///
/// \param text  Text object
/// \param scale New scale factors
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfText_setScale(sfText* text, sfVector2f scale);

////////////////////////////////////////////////////////////
/// \brief Set the local origin of a text
///
/// The origin of an object defines the center point for
/// all transformations (position, scale, rotation).
/// The coordinates of this point must be relative to the
/// top-left corner of the object, and ignore all
/// transformations (position, scale, rotation).
/// The default origin of a text object is (0, 0).
///
/// \param text   Text object
/// \param origin New origin
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfText_setOrigin(sfText* text, sfVector2f origin);

////////////////////////////////////////////////////////////
/// \brief Get the position of a text
///
/// \param text Text object
///
/// \return Current position
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API sfVector2f sfText_getPosition(const sfText* text);

////////////////////////////////////////////////////////////
/// \brief Get the orientation of a text
///
/// The rotation is always in the range [0, 360].
///
/// \param text Text object
///
/// \return Current rotation, in degrees
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API float sfText_getRotation(const sfText* text);

////////////////////////////////////////////////////////////
/// \brief Get the current scale of a text
///
/// \param text Text object
///
/// \return Current scale factors
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API sfVector2f sfText_getScale(const sfText* text);

////////////////////////////////////////////////////////////
/// \brief Get the local origin of a text
///
/// \param text Text object
///
/// \return Current origin
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API sfVector2f sfText_getOrigin(const sfText* text);

////////////////////////////////////////////////////////////
/// \brief Move a text by a given offset
///
/// This function adds to the current position of the object,
/// unlike sfText_setPosition which overwrites it.
///
/// \param text   Text object
/// \param offset Offset
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfText_move(sfText* text, sfVector2f offset);

////////////////////////////////////////////////////////////
/// \brief Rotate a text
///
/// This function adds to the current rotation of the object,
/// unlike sfText_setRotation which overwrites it.
///
/// \param text  Text object
/// \param angle Angle of rotation, in degrees
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfText_rotate(sfText* text, float angle);

////////////////////////////////////////////////////////////
/// \brief Scale a text
///
/// This function multiplies the current scale of the object,
/// unlike sfText_setScale which overwrites it.
///
/// \param text    Text object
/// \param factors Scale factors
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfText_scale(sfText* text, sfVector2f factors);

////////////////////////////////////////////////////////////
/// \brief Get the combined transform of a text
///
/// \param text Text object
///
/// \return Transform combining the position/rotation/scale/origin of the object
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API sfTransform sfText_getTransform(const sfText* text);

////////////////////////////////////////////////////////////
/// \brief Get the inverse of the combined transform of a text
///
/// \param text Text object
///
/// \return Inverse of the combined transformations applied to the object
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API sfTransform sfText_getInverseTransform(const sfText* text);

////////////////////////////////////////////////////////////
/// \brief Set the string of a text (from an ANSI string)
///
/// A text's string is empty by default.
///
/// \param text   Text object
/// \param string New string
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfText_setString(sfText* text, const char* string);

////////////////////////////////////////////////////////////
/// \brief Set the string of a text (from a unicode string)
///
/// \param text   Text object
/// \param string New string
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfText_setUnicodeString(sfText* text, const sfChar32* string);

////////////////////////////////////////////////////////////
/// \brief Set the font of a text
///
/// The \a font argument refers to a texture that must
/// exist as long as the text uses it. Indeed, the text
/// doesn't store its own copy of the font, but rather keeps
/// a pointer to the one that you passed to this function.
/// If the font is destroyed and the text tries to
/// use it, the behaviour is undefined.
///
/// \param text Text object
/// \param font New font
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfText_setFont(sfText* text, const sfFont* font);

////////////////////////////////////////////////////////////
/// \brief Set the character size of a text
///
/// The default size is 30.
///
/// \param text Text object
/// \param size New character size, in pixels
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfText_setCharacterSize(sfText* text, unsigned int size);

////////////////////////////////////////////////////////////
/// \brief Set the line spacing factor
///
/// The default spacing between lines is defined by the font.
/// This method enables you to set a factor for the spacing
/// between lines. By default the line spacing factor is 1.
///
/// \param text Text object
/// \param spacingFactor New line spacing factor
///
/// \see sfText_getLineSpacing
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfText_setLineSpacing(sfText* text, float spacingFactor);

////////////////////////////////////////////////////////////
/// \brief Set the letter spacing factor
///
/// The default spacing between letters is defined by the font.
/// This factor doesn't directly apply to the existing
/// spacing between each character, it rather adds a fixed
/// space between them which is calculated from the font
/// metrics and the character size.
/// Note that factors below 1 (including negative numbers) bring
/// characters closer to each other.
/// By default the letter spacing factor is 1.
///
/// \param text Text object
/// \param spacingFactor New letter spacing factor
///
/// \see sfText_getLetterSpacing
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfText_setLetterSpacing(sfText* text, float spacingFactor);

////////////////////////////////////////////////////////////
/// \brief Set the style of a text
///
/// You can pass a combination of one or more styles, for
/// example sfTextBold | sfTextItalic.
/// The default style is sfTextRegular.
///
/// \param text  Text object
/// \param style New style
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfText_setStyle(sfText* text, uint32_t style);

////////////////////////////////////////////////////////////
/// \brief Set the fill color of a text
///
/// By default, the text's fill color is opaque white.
/// Setting the fill color to a transparent color with an outline
/// will cause the outline to be displayed in the fill area of the text.
///
/// \param text  Text object
/// \param color New fill color of the text
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfText_setFillColor(sfText* text, sfColor color);

////////////////////////////////////////////////////////////
/// \brief Set the outline color of the text
///
/// By default, the text's outline color is opaque black.
///
/// \param text  Text object
/// \param color New outline color of the text
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfText_setOutlineColor(sfText* text, sfColor color);

////////////////////////////////////////////////////////////
/// \brief Set the thickness of the text's outline
///
/// By default, the outline thickness is 0.
///
/// Be aware that using a negative value for the outline
/// thickness will cause distorted rendering.
///
/// \param text      Text object
/// \param thickness New outline thickness, in pixels
///
/// \see getOutlineThickness
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfText_setOutlineThickness(sfText* text, float thickness);

////////////////////////////////////////////////////////////
/// \brief Set the line alignment for a multi-line text
///
/// By default, the line alignment is sfTextLineAlignmentDefault.
///
/// \param text          Text object
/// \param lineAlignment New line alignment
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfText_setLineAlignment(sfText* text, sfTextLineAlignment lineAlignment);

////////////////////////////////////////////////////////////
/// \brief Set the text orientation
///
/// By default, the text orientation is sfTextOrientationDefault.
///
/// Vertical text orientations require the font to provide
/// vertical metrics, see sfFontInfo.
///
/// \param text            Text object
/// \param textOrientation New text orientation
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfText_setTextOrientation(sfText* text, sfTextOrientation textOrientation);

////////////////////////////////////////////////////////////
/// \brief Get the string of a text (returns an ANSI string)
///
/// \param text Text object
///
/// \return String as a locale-dependant ANSI string
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API const char* sfText_getString(const sfText* text);

////////////////////////////////////////////////////////////
/// \brief Get the string of a text (returns a unicode string)
///
/// \param text Text object
///
/// \return String as UTF-32
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API const sfChar32* sfText_getUnicodeString(const sfText* text);

////////////////////////////////////////////////////////////
/// \brief Get the font used by a text
///
/// If the text has no font attached, a NULL pointer is returned.
/// The returned pointer is const, which means that you can't
/// modify the font when you retrieve it with this function.
///
/// \param text Text object
///
/// \return Pointer to the font
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API const sfFont* sfText_getFont(const sfText* text);

////////////////////////////////////////////////////////////
/// \brief Get the size of the characters of a text
///
/// \param text Text object
///
/// \return Size of the characters
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API unsigned int sfText_getCharacterSize(const sfText* text);

////////////////////////////////////////////////////////////
/// \brief Get the size of the letter spacing factor
///
/// \param text Text object
///
/// \return Size of the letter spacing factor
///
/// \see sfText_setLetterSpacing
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API float sfText_getLetterSpacing(const sfText* text);

////////////////////////////////////////////////////////////
/// \brief Get the size of the line spacing factor
///
/// \param text Text object
///
/// \return Size of the line spacing factor
///
/// \see sfText_setLineSpacing
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API float sfText_getLineSpacing(const sfText* text);

////////////////////////////////////////////////////////////
/// \brief Get the style of a text
///
/// \param text Text object
///
/// \return Current string style (see sfTextStyle enum)
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API uint32_t sfText_getStyle(const sfText* text);

////////////////////////////////////////////////////////////
/// \brief Get the fill color of a text
///
/// \param text Text object
///
/// \return Fill color of the text
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API sfColor sfText_getFillColor(const sfText* text);

////////////////////////////////////////////////////////////
/// \brief Get the outline color of a text
///
/// \param text Text object
///
/// \return Outline color of the text
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API sfColor sfText_getOutlineColor(const sfText* text);

////////////////////////////////////////////////////////////
/// \brief Get the outline thickness of a text
///
/// \param text Text object
///
/// \return Outline thickness of a text, in pixels
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API float sfText_getOutlineThickness(const sfText* text);

////////////////////////////////////////////////////////////
/// \brief Get the line alignment for a multi-line text
///
/// \param text Text object
///
/// \return Line alignment
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API sfTextLineAlignment sfText_getLineAlignment(const sfText* text);

////////////////////////////////////////////////////////////
/// \brief Get the text orientation
///
/// \param text Text object
///
/// \return Text orientation
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API sfTextOrientation sfText_getTextOrientation(const sfText* text);

////////////////////////////////////////////////////////////
/// \brief Return the position of the \a index-th character in a text
///
/// This function computes the visual position of a character
/// from its index in the string. The returned position is
/// in global coordinates (translation, rotation, scale and
/// origin are applied).
/// If \a index is out of range, the position of the end of
/// the string is returned.
///
/// \param text  Text object
/// \param index Index of the character
///
/// \return Position of the character
///
/// \deprecated Use sfText_getShapedGlyphs instead
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API CSFML_DEPRECATED sfVector2f sfText_findCharacterPos(const sfText* text, size_t index);

////////////////////////////////////////////////////////////
/// \brief Get the shaped glyphs that make up a text
///
/// The result of shaping, i.e. positioning individual glyphs
/// based on the properties of the font and the input text,
/// is a sequence of shaped glyphs. In addition to the glyph
/// information that is available by looking up a glyph from
/// a font, the glyph position, glyph cluster ID and direction
/// of the text represented by the glyph is provided.
///
/// When positioning e.g. a cursor within the text, grapheme
/// clusters can be treated as the basic units of which the
/// text is composed. See sfText_setClusterGrouping.
///
/// The returned glyph positions are in local coordinates
/// (translation, rotation, scale and origin are not applied).
///
/// The returned array is owned by the text and stays valid
/// until the next call to this function or until the text
/// is destroyed.
///
/// \param text  Text object
/// \param count Pointer to a variable that will be filled with the number of shaped glyphs
///
/// \return Pointer to the array of shaped glyphs
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API const sfShapedGlyph* sfText_getShapedGlyphs(const sfText* text, size_t* count);

////////////////////////////////////////////////////////////
/// \brief Get the cluster grouping algorithm in use
///
/// \param text Text object
///
/// \return The cluster grouping algorithm in use
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API sfTextClusterGrouping sfText_getClusterGrouping(const sfText* text);

////////////////////////////////////////////////////////////
/// \brief Set the cluster grouping algorithm to use
///
/// By default, character cluster grouping is used.
///
/// Character cluster grouping is good enough to be able to
/// position cursors in most scenarios. If more coarse-grained
/// grouping is required, grapheme grouping can be selected.
///
/// Cluster grouping can also be disabled if necessary.
///
/// \param text            Text object
/// \param clusterGrouping The cluster grouping algorithm to use
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfText_setClusterGrouping(sfText* text, sfTextClusterGrouping clusterGrouping);

////////////////////////////////////////////////////////////
/// \brief Set the glyph pre-processor to be called per glyph
///
/// The glyph pre-processor is called with glyph data to be
/// pre-processed whenever the text geometry is regenerated.
///
/// \param text              Text object
/// \param glyphPreProcessor The glyph pre-processor to be called per glyph, pass NULL to disable pre-processing
/// \param userData          User data that will be passed to the glyph pre-processor
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfText_setGlyphPreProcessor(sfText* text, sfGlyphPreProcessor glyphPreProcessor, void* userData);

////////////////////////////////////////////////////////////
/// \brief Get the vertex data of a text
///
/// The vertices form triangles (sfTriangles).
///
/// The vertex data is regenerated by the text whenever it is
/// necessary. Any changes made to the vertex data will be
/// discarded whenever this happens.
///
/// \param text  Text object
/// \param count Pointer to a variable that will be filled with the number of vertices
///
/// \return Pointer to the vertex data of the text
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API sfVertex* sfText_getVertexData(const sfText* text, size_t* count);

////////////////////////////////////////////////////////////
/// \brief Get the outline vertex data of a text
///
/// The vertices form triangles (sfTriangles).
///
/// The outline vertex data is regenerated by the text whenever
/// it is necessary. Any changes made to the outline vertex data
/// will be discarded whenever this happens.
///
/// \param text  Text object
/// \param count Pointer to a variable that will be filled with the number of vertices
///
/// \return Pointer to the outline vertex data of the text
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API sfVertex* sfText_getOutlineVertexData(const sfText* text, size_t* count);

////////////////////////////////////////////////////////////
/// \brief Get the local bounding rectangle of a text
///
/// The returned rectangle is in local coordinates, which means
/// that it ignores the transformations (translation, rotation,
/// scale, ...) that are applied to the entity.
/// In other words, this function returns the bounds of the
/// entity in the entity's coordinate system.
///
/// \param text Text object
///
/// \return Local bounding rectangle of the entity
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API sfFloatRect sfText_getLocalBounds(const sfText* text);

////////////////////////////////////////////////////////////
/// \brief Get the global bounding rectangle of a text
///
/// The returned rectangle is in global coordinates, which means
/// that it takes in account the transformations (translation,
/// rotation, scale, ...) that are applied to the entity.
/// In other words, this function returns the bounds of the
/// text in the global 2D world's coordinate system.
///
/// \param text Text object
///
/// \return Global bounding rectangle of the entity
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API sfFloatRect sfText_getGlobalBounds(const sfText* text);
