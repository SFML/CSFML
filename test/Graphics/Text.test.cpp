#include <CSFML/Graphics/Font.h>
#include <CSFML/Graphics/Text.h>

#include <SFML/Graphics/Text.hpp>

#include <catch2/catch_test_macros.hpp>

TEST_CASE("[Graphics] sfText")
{
    SECTION("sfTextLineAlignment")
    {
        STATIC_CHECK(sfTextLineAlignmentDefault == static_cast<int>(sf::Text::LineAlignment::Default));
        STATIC_CHECK(sfTextLineAlignmentLeft == static_cast<int>(sf::Text::LineAlignment::Left));
        STATIC_CHECK(sfTextLineAlignmentCenter == static_cast<int>(sf::Text::LineAlignment::Center));
        STATIC_CHECK(sfTextLineAlignmentRight == static_cast<int>(sf::Text::LineAlignment::Right));
    }

    SECTION("sfTextClusterGrouping")
    {
        STATIC_CHECK(sfTextClusterGroupingGrapheme == static_cast<int>(sf::Text::ClusterGrouping::Grapheme));
        STATIC_CHECK(sfTextClusterGroupingCharacter == static_cast<int>(sf::Text::ClusterGrouping::Character));
        STATIC_CHECK(sfTextClusterGroupingNone == static_cast<int>(sf::Text::ClusterGrouping::None));
    }

    SECTION("sfTextDirection")
    {
        STATIC_CHECK(sfTextDirectionUnspecified == static_cast<int>(sf::Text::TextDirection::Unspecified));
        STATIC_CHECK(sfTextDirectionLeftToRight == static_cast<int>(sf::Text::TextDirection::LeftToRight));
        STATIC_CHECK(sfTextDirectionRightToLeft == static_cast<int>(sf::Text::TextDirection::RightToLeft));
        STATIC_CHECK(sfTextDirectionTopToBottom == static_cast<int>(sf::Text::TextDirection::TopToBottom));
        STATIC_CHECK(sfTextDirectionBottomToTop == static_cast<int>(sf::Text::TextDirection::BottomToTop));
    }

    SECTION("sfTextOrientation")
    {
        STATIC_CHECK(sfTextOrientationDefault == static_cast<int>(sf::Text::TextOrientation::Default));
        STATIC_CHECK(sfTextOrientationTopToBottom == static_cast<int>(sf::Text::TextOrientation::TopToBottom));
        STATIC_CHECK(sfTextOrientationBottomToTop == static_cast<int>(sf::Text::TextOrientation::BottomToTop));
    }

    SECTION("Set/get layout properties")
    {
        sfFont* font = sfFont_createFromFile("Graphics/tuffy.ttf");
        REQUIRE(font != nullptr);
        sfText* text = sfText_create(font);

        CHECK(sfText_getLineAlignment(text) == sfTextLineAlignmentDefault);
        CHECK(sfText_getTextOrientation(text) == sfTextOrientationDefault);
        CHECK(sfText_getClusterGrouping(text) == sfTextClusterGroupingCharacter);

        sfText_setLineAlignment(text, sfTextLineAlignmentCenter);
        sfText_setTextOrientation(text, sfTextOrientationTopToBottom);
        sfText_setClusterGrouping(text, sfTextClusterGroupingGrapheme);

        CHECK(sfText_getLineAlignment(text) == sfTextLineAlignmentCenter);
        CHECK(sfText_getTextOrientation(text) == sfTextOrientationTopToBottom);
        CHECK(sfText_getClusterGrouping(text) == sfTextClusterGroupingGrapheme);

        sfText* copy = sfText_copy(text);
        CHECK(sfText_getLineAlignment(copy) == sfTextLineAlignmentCenter);
        sfText_destroy(copy);

        sfText_destroy(text);
        sfFont_destroy(font);
    }
}
