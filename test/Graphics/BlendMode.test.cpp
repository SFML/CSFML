#include <CSFML/Graphics/BlendMode.h>

#include <SFML/Graphics/BlendMode.hpp>

#include <catch2/catch_test_macros.hpp>

TEST_CASE("[Graphics] sfBlendMode")
{
    SECTION("sfBlendFactor")
    {
        STATIC_CHECK(sfBlendFactorZero == static_cast<int>(sf::BlendMode::Factor::Zero));
        STATIC_CHECK(sfBlendFactorOne == static_cast<int>(sf::BlendMode::Factor::One));
        STATIC_CHECK(sfBlendFactorSrcColor == static_cast<int>(sf::BlendMode::Factor::SrcColor));
        STATIC_CHECK(sfBlendFactorOneMinusSrcColor == static_cast<int>(sf::BlendMode::Factor::OneMinusSrcColor));
        STATIC_CHECK(sfBlendFactorDstColor == static_cast<int>(sf::BlendMode::Factor::DstColor));
        STATIC_CHECK(sfBlendFactorOneMinusDstColor == static_cast<int>(sf::BlendMode::Factor::OneMinusDstColor));
        STATIC_CHECK(sfBlendFactorSrcAlpha == static_cast<int>(sf::BlendMode::Factor::SrcAlpha));
        STATIC_CHECK(sfBlendFactorOneMinusSrcAlpha == static_cast<int>(sf::BlendMode::Factor::OneMinusSrcAlpha));
        STATIC_CHECK(sfBlendFactorDstAlpha == static_cast<int>(sf::BlendMode::Factor::DstAlpha));
        STATIC_CHECK(sfBlendFactorOneMinusDstAlpha == static_cast<int>(sf::BlendMode::Factor::OneMinusDstAlpha));
    }

    SECTION("sfBlendEquation")
    {
        STATIC_CHECK(sfBlendEquationAdd == static_cast<int>(sf::BlendMode::Equation::Add));
        STATIC_CHECK(sfBlendEquationSubtract == static_cast<int>(sf::BlendMode::Equation::Subtract));
        STATIC_CHECK(sfBlendEquationReverseSubtract == static_cast<int>(sf::BlendMode::Equation::ReverseSubtract));
        STATIC_CHECK(sfBlendEquationMin == static_cast<int>(sf::BlendMode::Equation::Min));
        STATIC_CHECK(sfBlendEquationMax == static_cast<int>(sf::BlendMode::Equation::Max));
    }

    SECTION("Construction")
    {
        constexpr sfBlendMode blendMode{};
        STATIC_CHECK(blendMode.colorSrcFactor == sfBlendFactorZero);
        STATIC_CHECK(blendMode.colorDstFactor == sfBlendFactorZero);
        STATIC_CHECK(blendMode.colorEquation == sfBlendEquationAdd);
        STATIC_CHECK(blendMode.alphaSrcFactor == sfBlendFactorZero);
        STATIC_CHECK(blendMode.alphaDstFactor == sfBlendFactorZero);
        STATIC_CHECK(blendMode.alphaEquation == sfBlendEquationAdd);
    }

    SECTION("Constants")
    {
        SECTION("sfBlendAlpha")
        {
            CHECK(sfBlendAlpha.colorSrcFactor == sfBlendFactorSrcAlpha);
            CHECK(sfBlendAlpha.colorDstFactor == sfBlendFactorOneMinusSrcAlpha);
            CHECK(sfBlendAlpha.colorEquation == sfBlendEquationAdd);
            CHECK(sfBlendAlpha.alphaSrcFactor == sfBlendFactorOne);
            CHECK(sfBlendAlpha.alphaDstFactor == sfBlendFactorOneMinusSrcAlpha);
            CHECK(sfBlendAlpha.alphaEquation == sfBlendEquationAdd);
        }

        SECTION("sfBlendAdd")
        {
            CHECK(sfBlendAdd.colorSrcFactor == sfBlendFactorSrcAlpha);
            CHECK(sfBlendAdd.colorDstFactor == sfBlendFactorOne);
            CHECK(sfBlendAdd.colorEquation == sfBlendEquationAdd);
            CHECK(sfBlendAdd.alphaSrcFactor == sfBlendFactorOne);
            CHECK(sfBlendAdd.alphaDstFactor == sfBlendFactorOne);
            CHECK(sfBlendAdd.alphaEquation == sfBlendEquationAdd);
        }

        SECTION("sfBlendMultiply")
        {
            CHECK(sfBlendMultiply.colorSrcFactor == sfBlendFactorDstColor);
            CHECK(sfBlendMultiply.colorDstFactor == sfBlendFactorZero);
            CHECK(sfBlendMultiply.colorEquation == sfBlendEquationAdd);
            CHECK(sfBlendMultiply.alphaSrcFactor == sfBlendFactorDstColor);
            CHECK(sfBlendMultiply.alphaDstFactor == sfBlendFactorZero);
            CHECK(sfBlendMultiply.alphaEquation == sfBlendEquationAdd);
        }

        SECTION("sfBlendMin")
        {
            CHECK(sfBlendMin.colorSrcFactor == sfBlendFactorOne);
            CHECK(sfBlendMin.colorDstFactor == sfBlendFactorOne);
            CHECK(sfBlendMin.colorEquation == sfBlendEquationMin);
            CHECK(sfBlendMin.alphaSrcFactor == sfBlendFactorOne);
            CHECK(sfBlendMin.alphaDstFactor == sfBlendFactorOne);
            CHECK(sfBlendMin.alphaEquation == sfBlendEquationMin);
        }

        SECTION("sfBlendMax")
        {
            CHECK(sfBlendMax.colorSrcFactor == sfBlendFactorOne);
            CHECK(sfBlendMax.colorDstFactor == sfBlendFactorOne);
            CHECK(sfBlendMax.colorEquation == sfBlendEquationMax);
            CHECK(sfBlendMax.alphaSrcFactor == sfBlendFactorOne);
            CHECK(sfBlendMax.alphaDstFactor == sfBlendFactorOne);
            CHECK(sfBlendMax.alphaEquation == sfBlendEquationMax);
        }

        SECTION("sfBlendNone")
        {
            CHECK(sfBlendNone.colorSrcFactor == sfBlendFactorOne);
            CHECK(sfBlendNone.colorDstFactor == sfBlendFactorZero);
            CHECK(sfBlendNone.colorEquation == sfBlendEquationAdd);
            CHECK(sfBlendNone.alphaSrcFactor == sfBlendFactorOne);
            CHECK(sfBlendNone.alphaDstFactor == sfBlendFactorZero);
            CHECK(sfBlendNone.alphaEquation == sfBlendEquationAdd);
        }
    }
}
