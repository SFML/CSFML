#include <CSFML/Window/Cursor.h>

#include <SFML/Window/Cursor.hpp>

#include <catch2/catch_test_macros.hpp>

#include <array>

TEST_CASE("[Window] sfCursor")
{
    SECTION("sfCursorType")
    {
        STATIC_CHECK(sfCursorArrow == static_cast<int>(sf::Cursor::Type::Arrow));
        STATIC_CHECK(sfCursorArrowWait == static_cast<int>(sf::Cursor::Type::ArrowWait));
        STATIC_CHECK(sfCursorWait == static_cast<int>(sf::Cursor::Type::Wait));
        STATIC_CHECK(sfCursorText == static_cast<int>(sf::Cursor::Type::Text));
        STATIC_CHECK(sfCursorHand == static_cast<int>(sf::Cursor::Type::Hand));
        STATIC_CHECK(sfCursorSizeHorizontal == static_cast<int>(sf::Cursor::Type::SizeHorizontal));
        STATIC_CHECK(sfCursorSizeVertical == static_cast<int>(sf::Cursor::Type::SizeVertical));
        STATIC_CHECK(sfCursorSizeTopLeftBottomRight == static_cast<int>(sf::Cursor::Type::SizeTopLeftBottomRight));
        STATIC_CHECK(sfCursorSizeBottomLeftTopRight == static_cast<int>(sf::Cursor::Type::SizeBottomLeftTopRight));
        STATIC_CHECK(sfCursorSizeLeft == static_cast<int>(sf::Cursor::Type::SizeLeft));
        STATIC_CHECK(sfCursorSizeRight == static_cast<int>(sf::Cursor::Type::SizeRight));
        STATIC_CHECK(sfCursorSizeTop == static_cast<int>(sf::Cursor::Type::SizeTop));
        STATIC_CHECK(sfCursorSizeBottom == static_cast<int>(sf::Cursor::Type::SizeBottom));
        STATIC_CHECK(sfCursorSizeTopLeft == static_cast<int>(sf::Cursor::Type::SizeTopLeft));
        STATIC_CHECK(sfCursorSizeBottomRight == static_cast<int>(sf::Cursor::Type::SizeBottomRight));
        STATIC_CHECK(sfCursorSizeBottomLeft == static_cast<int>(sf::Cursor::Type::SizeBottomLeft));
        STATIC_CHECK(sfCursorSizeTopRight == static_cast<int>(sf::Cursor::Type::SizeTopRight));
        STATIC_CHECK(sfCursorSizeAll == static_cast<int>(sf::Cursor::Type::SizeAll));
        STATIC_CHECK(sfCursorCross == static_cast<int>(sf::Cursor::Type::Cross));
        STATIC_CHECK(sfCursorHelp == static_cast<int>(sf::Cursor::Type::Help));
        STATIC_CHECK(sfCursorNotAllowed == static_cast<int>(sf::Cursor::Type::NotAllowed));
    }

    SECTION("sfCursor_createFromPixels")
    {
        static constexpr std::array<std::uint8_t, 4> pixels{};
        sfCursor*                                    cursor = sfCursor_createFromPixels(pixels.data(), {1, 1}, {});
        CHECK(cursor);
        sfCursor_destroy(cursor);
    }

    SECTION("sfCursor_createFromSystem")
    {
        sfCursor* cursor{};

        SECTION("sfCursorArrow")
        {
            cursor = sfCursor_createFromSystem(sfCursorArrow);
        }

        SECTION("sfCursorArrowWait")
        {
            cursor = sfCursor_createFromSystem(sfCursorArrowWait);
        }

        SECTION("sfCursorWait")
        {
            cursor = sfCursor_createFromSystem(sfCursorWait);
        }

        CHECK(cursor);
        sfCursor_destroy(cursor);
    }
}
