#include <CSFML/Graphics/StencilMode.h>

#include <SFML/Graphics/StencilMode.hpp>

#include <catch2/catch_test_macros.hpp>

TEST_CASE("[Graphics] sfStencilMode")
{
    SECTION("sfStencilComparison")
    {
        STATIC_CHECK(sfStencilComparisonNever == static_cast<int>(sf::StencilComparison::Never));
        STATIC_CHECK(sfStencilComparisonLess == static_cast<int>(sf::StencilComparison::Less));
        STATIC_CHECK(sfStencilComparisonLessEqual == static_cast<int>(sf::StencilComparison::LessEqual));
        STATIC_CHECK(sfStencilComparisonGreater == static_cast<int>(sf::StencilComparison::Greater));
        STATIC_CHECK(sfStencilComparisonGreaterEqual == static_cast<int>(sf::StencilComparison::GreaterEqual));
        STATIC_CHECK(sfStencilComparisonEqual == static_cast<int>(sf::StencilComparison::Equal));
        STATIC_CHECK(sfStencilComparisonNotEqual == static_cast<int>(sf::StencilComparison::NotEqual));
        STATIC_CHECK(sfStencilComparisonAlways == static_cast<int>(sf::StencilComparison::Always));
    }

    SECTION("sfStencilUpdateOperation")
    {
        STATIC_CHECK(sfStencilUpdateOperationKeep == static_cast<int>(sf::StencilUpdateOperation::Keep));
        STATIC_CHECK(sfStencilUpdateOperationZero == static_cast<int>(sf::StencilUpdateOperation::Zero));
        STATIC_CHECK(sfStencilUpdateOperationReplace == static_cast<int>(sf::StencilUpdateOperation::Replace));
        STATIC_CHECK(sfStencilUpdateOperationIncrement == static_cast<int>(sf::StencilUpdateOperation::Increment));
        STATIC_CHECK(sfStencilUpdateOperationDecrement == static_cast<int>(sf::StencilUpdateOperation::Decrement));
        STATIC_CHECK(sfStencilUpdateOperationInvert == static_cast<int>(sf::StencilUpdateOperation::Invert));
    }

    SECTION("sfStencilValue")
    {
        constexpr sfStencilValue stencilValue{};
        STATIC_CHECK(stencilValue.value == 0);
    }

    SECTION("sfStencilMode")
    {
        constexpr sfStencilMode stencilMode{};
        STATIC_CHECK(stencilMode.stencilComparison == sfStencilComparisonNever);
        STATIC_CHECK(stencilMode.stencilUpdateOperation == sfStencilUpdateOperationKeep);
        STATIC_CHECK(stencilMode.stencilReference.value == 0);
        STATIC_CHECK(stencilMode.stencilMask.value == 0);
        STATIC_CHECK(!stencilMode.stencilOnly);
    }

    SECTION("sfStencilMode_default")
    {
        CHECK(sfStencilMode_default.stencilComparison == sfStencilComparisonAlways);
        CHECK(sfStencilMode_default.stencilUpdateOperation == sfStencilUpdateOperationKeep);
        CHECK(sfStencilMode_default.stencilReference.value == 0);
        CHECK(sfStencilMode_default.stencilMask.value == ~0u);
        CHECK(!sfStencilMode_default.stencilOnly);
    }
}
