#include <CSFML/Graphics/VertexArray.h>

#include <catch2/catch_test_macros.hpp>

TEST_CASE("[Graphics] sfVertexArray")
{
    SECTION("sfVertexArray_create")
    {
        const sfVertexArray* vertexArray = sfVertexArray_create();
        CHECK(sfVertexArray_getVertexCount(vertexArray) == 0);
        CHECK(sfVertexArray_getPrimitiveType(vertexArray) == sfPoints);
        const sfFloatRect bounds = sfVertexArray_getBounds(vertexArray);
        CHECK(bounds.position.x == 0);
        CHECK(bounds.position.y == 0);
        CHECK(bounds.size.x == 0);
        CHECK(bounds.size.y == 0);
        sfVertexArray_destroy(vertexArray);
    }

    SECTION("sfVertexArray_copy")
    {
        sfVertexArray* vertexArray1 = sfVertexArray_create();
        sfVertexArray_resize(vertexArray1, 10);
        sfVertexArray_setPrimitiveType(vertexArray1, sfLines);
        const sfVertexArray* vertexArray2 = sfVertexArray_copy(vertexArray1);
        CHECK(sfVertexArray_getVertexCount(vertexArray2) == 10);
        CHECK(sfVertexArray_getPrimitiveType(vertexArray2) == sfLines);
        sfVertexArray_destroy(vertexArray2);
        sfVertexArray_destroy(vertexArray1);
    }

    SECTION("sfVertexArray_resize")
    {
        sfVertexArray* vertexArray = sfVertexArray_create();
        sfVertexArray_resize(vertexArray, 42);
        const auto vertexCount = sfVertexArray_getVertexCount(vertexArray);
        CHECK(vertexCount == 42);
        for (std::size_t i = 0; i < vertexCount; ++i)
        {
            const auto& vertex = *sfVertexArray_getVertex(vertexArray, i);
            CHECK(vertex.position.x == 0);
            CHECK(vertex.position.y == 0);
            CHECK(+vertex.color.r == sfWhite.r);
            CHECK(+vertex.color.g == sfWhite.g);
            CHECK(+vertex.color.b == sfWhite.b);
            CHECK(+vertex.color.a == sfWhite.a);
            CHECK(vertex.texCoords.x == 0);
            CHECK(vertex.texCoords.y == 0);
        }
        sfVertexArray_destroy(vertexArray);
    }

    SECTION("sfVertexArray_clear")
    {
        sfVertexArray* vertexArray = sfVertexArray_create();
        sfVertexArray_resize(vertexArray, 13);
        sfVertexArray_setPrimitiveType(vertexArray, sfLines);
        sfVertexArray_clear(vertexArray);
        CHECK(sfVertexArray_getVertexCount(vertexArray) == 0);
        CHECK(sfVertexArray_getPrimitiveType(vertexArray) == sfLines);
        sfVertexArray_destroy(vertexArray);
    }

    SECTION("sfVertexArray_append")
    {
        sfVertexArray* vertexArray = sfVertexArray_create();
        sfVertexArray_append(vertexArray, {{1, 2}, {3, 4, 5, 6}, {7, 8}});
        CHECK(sfVertexArray_getVertexCount(vertexArray) == 1);
        const auto& vertex = *sfVertexArray_getVertex(vertexArray, 0);
        CHECK(vertex.position.x == 1);
        CHECK(vertex.position.y == 2);
        CHECK(+vertex.color.r == 3);
        CHECK(+vertex.color.g == 4);
        CHECK(+vertex.color.b == 5);
        CHECK(+vertex.color.a == 6);
        CHECK(vertex.texCoords.x == 7);
        CHECK(vertex.texCoords.y == 8);
        sfVertexArray_destroy(vertexArray);
    }

    SECTION("sfVertexArray_getBounds")
    {
        sfVertexArray* vertexArray = sfVertexArray_create();
        sfVertexArray_append(vertexArray, {{1, 1}, {}, {}});
        sfVertexArray_append(vertexArray, {{2, 2}, {}, {}});

        sfFloatRect bounds = sfVertexArray_getBounds(vertexArray);
        CHECK(bounds.position.x == 1);
        CHECK(bounds.position.y == 1);
        CHECK(bounds.size.x == 1);
        CHECK(bounds.size.y == 1);

        *sfVertexArray_getVertex(vertexArray, 0) = {{0, 0}, {}, {}};
        bounds                                   = sfVertexArray_getBounds(vertexArray);
        CHECK(bounds.position.x == 0);
        CHECK(bounds.position.y == 0);
        CHECK(bounds.size.x == 2);
        CHECK(bounds.size.y == 2);

        *sfVertexArray_getVertex(vertexArray, 0) = {{5, 5}, {}, {}};
        bounds                                   = sfVertexArray_getBounds(vertexArray);
        CHECK(bounds.position.x == 2);
        CHECK(bounds.position.y == 2);
        CHECK(bounds.size.x == 3);
        CHECK(bounds.size.y == 3);

        sfVertexArray_append(vertexArray, {{10, 10}, {}, {}});
        bounds = sfVertexArray_getBounds(vertexArray);
        CHECK(bounds.position.x == 2);
        CHECK(bounds.position.y == 2);
        CHECK(bounds.size.x == 8);
        CHECK(bounds.size.y == 8);

        sfVertexArray_destroy(vertexArray);
    }
}
