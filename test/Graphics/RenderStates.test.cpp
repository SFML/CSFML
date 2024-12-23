#include <CSFML/Graphics/RenderStates.h>

#include <SFML/Graphics/RenderStates.hpp>

#include <catch2/catch_test_macros.hpp>

#include "CSFML/Graphics/CoordinateType.h"

TEST_CASE("[Graphics] sfRenderStates")
{
    SECTION("Construction")
    {
        constexpr sfRenderStates renderStates{};
        STATIC_CHECK(renderStates.blendMode.colorSrcFactor == sfBlendFactorZero);
        STATIC_CHECK(renderStates.blendMode.colorDstFactor == sfBlendFactorZero);
        STATIC_CHECK(renderStates.blendMode.colorEquation == sfBlendEquationAdd);
        STATIC_CHECK(renderStates.blendMode.alphaSrcFactor == sfBlendFactorZero);
        STATIC_CHECK(renderStates.blendMode.alphaDstFactor == sfBlendFactorZero);
        STATIC_CHECK(renderStates.blendMode.alphaEquation == sfBlendEquationAdd);
        STATIC_CHECK(renderStates.stencilMode.stencilComparison == sfStencilComparisonNever);
        STATIC_CHECK(renderStates.stencilMode.stencilUpdateOperation == sfStencilUpdateOperationKeep);
        STATIC_CHECK(renderStates.stencilMode.stencilReference.value == 0);
        STATIC_CHECK(renderStates.stencilMode.stencilMask.value == 0);
        STATIC_CHECK(!renderStates.stencilMode.stencilOnly);
        for (const auto element : renderStates.transform.matrix)
            CHECK(element == 0);
        STATIC_CHECK(renderStates.coordinateType == sfCoordinateTypeNormalized);
        STATIC_CHECK(renderStates.texture == nullptr);
        STATIC_CHECK(renderStates.shader == nullptr);
    }

    SECTION("sfRenderStates_default")
    {
        CHECK(sfRenderStates_default.blendMode.alphaDstFactor == sfBlendAlpha.alphaDstFactor);
        CHECK(sfRenderStates_default.blendMode.colorDstFactor == sfBlendAlpha.colorDstFactor);
        CHECK(sfRenderStates_default.blendMode.colorEquation == sfBlendAlpha.colorEquation);
        CHECK(sfRenderStates_default.blendMode.alphaSrcFactor == sfBlendAlpha.alphaSrcFactor);
        CHECK(sfRenderStates_default.blendMode.alphaDstFactor == sfBlendAlpha.alphaDstFactor);
        CHECK(sfRenderStates_default.blendMode.alphaEquation == sfBlendAlpha.alphaEquation);
    }
}
