#include <CSFML/Graphics/Shape.h>

#include <catch2/catch_test_macros.hpp>

TEST_CASE("[Graphics] sfShape")
{
    const auto getPointCount = [](void* userData) -> std::size_t
    { return static_cast<std::vector<sfVector2f>*>(userData)->size(); };
    const auto getPoint = [](std::size_t index, void* userData) -> sfVector2f
    { return static_cast<std::vector<sfVector2f>*>(userData)->operator[](index); };
    std::vector<sfVector2f> points = {{0, 0}, {30, 0}, {0, 30}};

    SECTION("sfShape_create")
    {
        const sfShape*   shape    = sfShape_create(getPointCount, getPoint, &points);
        const sfVector2f position = sfShape_getPosition(shape);
        CHECK(position.x == 0);
        CHECK(position.y == 0);
        CHECK(sfShape_getRotation(shape) == 0);
        const sfVector2f scale = sfShape_getScale(shape);
        CHECK(scale.x == 1);
        CHECK(scale.y == 1);
        const sfVector2f origin = sfShape_getOrigin(shape);
        CHECK(origin.x == 0);
        CHECK(origin.y == 0);
        const sfTransform transform = sfShape_getTransform(shape);
        const std::vector matrix(std::data(transform.matrix), std::data(transform.matrix) + std::size(transform.matrix));
        CHECK(matrix == std::vector<float>({1, 0, 0, 0, 1, 0, 0, 0, 1}));
        const sfTransform inverseTransform = sfShape_getInverseTransform(shape);
        const std::vector inverseMatrix(std::data(inverseTransform.matrix),
                                        std::data(inverseTransform.matrix) + std::size(inverseTransform.matrix));
        CHECK(inverseMatrix == std::vector<float>({1, 0, 0, 0, 1, 0, 0, 0, 1}));
        CHECK(sfShape_getTexture(shape) == nullptr);
        const sfIntRect textureRect = sfShape_getTextureRect(shape);
        CHECK(textureRect.position.x == 0);
        CHECK(textureRect.position.y == 0);
        CHECK(textureRect.size.x == 0);
        CHECK(textureRect.size.y == 0);
        const sfColor fillColor = sfShape_getFillColor(shape);
        CHECK(fillColor.r == sfWhite.r);
        CHECK(fillColor.g == sfWhite.g);
        CHECK(fillColor.b == sfWhite.b);
        CHECK(fillColor.a == sfWhite.a);
        const sfColor outlineColor = sfShape_getOutlineColor(shape);
        CHECK(outlineColor.r == sfWhite.r);
        CHECK(outlineColor.g == sfWhite.g);
        CHECK(outlineColor.b == sfWhite.b);
        CHECK(outlineColor.a == sfWhite.a);
        CHECK(sfShape_getOutlineThickness(shape) == 0);
        CHECK(sfShape_getPointCount(shape) == 3);
        const sfVector2f point = sfShape_getPoint(shape, 0);
        CHECK(point.x == 0);
        CHECK(point.y == 0);
        const sfVector2f geometricCenter = sfShape_getGeometricCenter(shape);
        CHECK(geometricCenter.x == 10);
        CHECK(geometricCenter.y == 10);
        const sfFloatRect localBounds = sfShape_getLocalBounds(shape);
        CHECK(localBounds.position.x == 0);
        CHECK(localBounds.position.y == 0);
        CHECK(localBounds.size.x == 0);
        CHECK(localBounds.size.y == 0);
        const sfFloatRect globalBounds = sfShape_getGlobalBounds(shape);
        CHECK(globalBounds.position.x == 0);
        CHECK(globalBounds.position.y == 0);
        CHECK(globalBounds.size.x == 0);
        CHECK(globalBounds.size.y == 0);
        sfShape_destroy(shape);
    }

    SECTION("Set/get position")
    {
        sfShape* shape = sfShape_create(getPointCount, getPoint, &points);
        sfShape_setPosition(shape, {10, 20});
        const sfVector2f position = sfShape_getPosition(shape);
        CHECK(position.x == 10);
        CHECK(position.y == 20);
        sfShape_destroy(shape);
    }

    SECTION("Set/get rotation")
    {
        sfShape* shape = sfShape_create(getPointCount, getPoint, &points);
        sfShape_setRotation(shape, 45);
        CHECK(sfShape_getRotation(shape) == 45);
        sfShape_destroy(shape);
    }

    SECTION("Set/get scale")
    {
        sfShape* shape = sfShape_create(getPointCount, getPoint, &points);
        sfShape_setScale(shape, {0.5f, 0.75f});
        const sfVector2f scale = sfShape_getScale(shape);
        CHECK(scale.x == 0.5f);
        CHECK(scale.y == 0.75f);
        sfShape_destroy(shape);
    }

    SECTION("Set/get origin")
    {
        sfShape* shape = sfShape_create(getPointCount, getPoint, &points);
        sfShape_setOrigin(shape, {80, 90});
        const sfVector2f origin = sfShape_getOrigin(shape);
        CHECK(origin.x == 80);
        CHECK(origin.y == 90);
        sfShape_destroy(shape);
    }
}
