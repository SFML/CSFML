#include <CSFML/Graphics/Transform.h>

#include <catch2/catch_test_macros.hpp>

#include <array>

TEST_CASE("[Graphics] sfTransform")
{
    SECTION("Construction")
    {
        constexpr sfTransform transform{};
        STATIC_CHECK(std::size(transform.matrix) == 9);
        for (const auto element : transform.matrix)
            CHECK(element == 0);
    }

    SECTION("sfTransform_Identity")
    {
        CHECK(sfTransform_Identity.matrix[0] == 1);
        CHECK(sfTransform_Identity.matrix[1] == 0);
        CHECK(sfTransform_Identity.matrix[2] == 0);
        CHECK(sfTransform_Identity.matrix[3] == 0);
        CHECK(sfTransform_Identity.matrix[4] == 1);
        CHECK(sfTransform_Identity.matrix[5] == 0);
        CHECK(sfTransform_Identity.matrix[6] == 0);
        CHECK(sfTransform_Identity.matrix[7] == 0);
        CHECK(sfTransform_Identity.matrix[8] == 1);
    }

    SECTION("sfTransform_fromMatrix")
    {
        const auto transform = sfTransform_fromMatrix(1, 2, 3, 4, 5, 6, 7, 8, 9);
        CHECK(transform.matrix[0] == 1);
        CHECK(transform.matrix[1] == 2);
        CHECK(transform.matrix[2] == 3);
        CHECK(transform.matrix[3] == 4);
        CHECK(transform.matrix[4] == 5);
        CHECK(transform.matrix[5] == 6);
        CHECK(transform.matrix[6] == 7);
        CHECK(transform.matrix[7] == 8);
        CHECK(transform.matrix[8] == 9);
    }

    SECTION("sfTransform_getMatrix")
    {
        const auto            transform = sfTransform_fromMatrix(1, 2, 3, 4, 5, 6, 7, 8, 9);
        std::array<float, 16> matrix{};
        matrix.fill(std::numeric_limits<float>::signaling_NaN());
        sfTransform_getMatrix(&transform, matrix.data());
        CHECK(matrix[0] == 1);
        CHECK(matrix[1] == 4);
        CHECK(matrix[2] == 0);
        CHECK(matrix[3] == 7);
        CHECK(matrix[4] == 2);
        CHECK(matrix[5] == 5);
        CHECK(matrix[6] == 0);
        CHECK(matrix[7] == 8);
        CHECK(matrix[8] == 0);
        CHECK(matrix[9] == 0);
        CHECK(matrix[10] == 1);
        CHECK(matrix[11] == 0);
        CHECK(matrix[12] == 3);
        CHECK(matrix[13] == 6);
        CHECK(matrix[14] == 0);
        CHECK(matrix[15] == 9);
    }

    SECTION("sfTransform_getInverse")
    {
        SECTION("Identity")
        {
            const auto inverse = sfTransform_getInverse(&sfTransform_Identity);
            for (std::size_t i = 0; i < std::size(inverse.matrix); ++i)
                CHECK(inverse.matrix[0] == sfTransform_Identity.matrix[0]);
        }

        SECTION("Non-identity")
        {
            const auto transform = sfTransform_fromMatrix(1, 2, 3, 4, 5, 4, 3, 2, 1);
            const auto inverse   = sfTransform_getInverse(&transform);
            CHECK(inverse.matrix[0] == 0.375f);
            CHECK(inverse.matrix[1] == -0.5f);
            CHECK(inverse.matrix[2] == 0.875f);
            CHECK(inverse.matrix[3] == -1);
            CHECK(inverse.matrix[4] == 1);
            CHECK(inverse.matrix[5] == -1);
            CHECK(inverse.matrix[6] == 0.875f);
            CHECK(inverse.matrix[7] == -0.5f);
            CHECK(inverse.matrix[8] == 0.375f);
        }
    }

    SECTION("sfTransform_transformPoint")
    {
    }

    SECTION("sfTransform_transformRect")
    {
    }

    SECTION("sfTransform_combine")
    {
    }

    SECTION("sfTransform_translate")
    {
    }

    SECTION("sfTransform_rotate")
    {
    }

    SECTION("sfTransform_rotateWithCenter")
    {
    }

    SECTION("sfTransform_scale")
    {
    }

    SECTION("sfTransform_scaleWithCenter")
    {
    }

    SECTION("sfTransform_equal")
    {
    }
}
