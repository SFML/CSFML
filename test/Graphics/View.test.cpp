#include <CSFML/Graphics/View.h>

#include <catch2/catch_test_macros.hpp>

TEST_CASE("[Graphics] sfView")
{
    SECTION("sfView_create")
    {
        const sfView*    view   = sfView_create();
        const sfVector2f center = sfView_getCenter(view);
        CHECK(center.x == 500);
        CHECK(center.y == 500);
        const sfVector2f size = sfView_getSize(view);
        CHECK(size.x == 1000);
        CHECK(size.y == 1000);
        CHECK(sfView_getRotation(view) == 0);
        const sfFloatRect viewport = sfView_getViewport(view);
        CHECK(viewport.position.x == 0);
        CHECK(viewport.position.y == 0);
        CHECK(viewport.size.x == 1);
        CHECK(viewport.size.y == 1);
        const sfFloatRect scissor = sfView_getScissor(view);
        CHECK(scissor.position.x == 0);
        CHECK(scissor.position.y == 0);
        CHECK(scissor.size.x == 1);
        CHECK(scissor.size.y == 1);
        sfView_destroy(view);
    }

    SECTION("sfView_createFromRect")
    {
        const sfView*    view   = sfView_createFromRect({{50, 100}, {240, 360}});
        const sfVector2f center = sfView_getCenter(view);
        CHECK(center.x == 170);
        CHECK(center.y == 280);
        const sfVector2f size = sfView_getSize(view);
        CHECK(size.x == 240);
        CHECK(size.y == 360);
        CHECK(sfView_getRotation(view) == 0);
        const sfFloatRect viewport = sfView_getViewport(view);
        CHECK(viewport.position.x == 0);
        CHECK(viewport.position.y == 0);
        CHECK(viewport.size.x == 1);
        CHECK(viewport.size.y == 1);
        const sfFloatRect scissor = sfView_getScissor(view);
        CHECK(scissor.position.x == 0);
        CHECK(scissor.position.y == 0);
        CHECK(scissor.size.x == 1);
        CHECK(scissor.size.y == 1);
        sfView_destroy(view);
    }

    SECTION("sfView_copy")
    {
        sfView* view1 = sfView_createFromRect({{50, 100}, {240, 360}});
        sfView_setViewport(view1, {{25, 40}, {100, 200}});
        sfView_setScissor(view1, {{0.75f, 0.25f}, {0, 0.5f}});
        const sfView*    view2  = sfView_copy(view1);
        const sfVector2f center = sfView_getCenter(view2);
        CHECK(center.x == 170);
        CHECK(center.y == 280);
        const sfVector2f size = sfView_getSize(view2);
        CHECK(size.x == 240);
        CHECK(size.y == 360);
        CHECK(sfView_getRotation(view2) == 0);
        const sfFloatRect viewport = sfView_getViewport(view2);
        CHECK(viewport.position.x == 25);
        CHECK(viewport.position.y == 40);
        CHECK(viewport.size.x == 100);
        CHECK(viewport.size.y == 200);
        const sfFloatRect scissor = sfView_getScissor(view2);
        CHECK(scissor.position.x == 0.75f);
        CHECK(scissor.position.y == 0.25f);
        CHECK(scissor.size.x == 0);
        CHECK(scissor.size.y == 0.5f);
        sfView_destroy(view2);
        sfView_destroy(view1);
    }

    SECTION("sfView_setCenter")
    {
        sfView* view = sfView_create();
        sfView_setCenter(view, {400, 600});
        const sfVector2f center = sfView_getCenter(view);
        CHECK(center.x == 400);
        CHECK(center.y == 600);
        sfView_destroy(view);
    }

    SECTION("sfView_setSize")
    {
        sfView* view = sfView_create();
        sfView_setSize(view, {150, 350});
        const sfVector2f size = sfView_getSize(view);
        CHECK(size.x == 150);
        CHECK(size.y == 350);
        sfView_destroy(view);
    }

    SECTION("sfView_setRotation")
    {
        sfView* view = sfView_create();
        sfView_setRotation(view, 45);
        CHECK(sfView_getRotation(view) == 45);
        sfView_destroy(view);
    }

    SECTION("sfView_setViewport")
    {
        sfView* view = sfView_create();
        sfView_setViewport(view, {{25, 40}, {100, 200}});
        const sfFloatRect viewport = sfView_getViewport(view);
        CHECK(viewport.position.x == 25);
        CHECK(viewport.position.y == 40);
        CHECK(viewport.size.x == 100);
        CHECK(viewport.size.y == 200);
        sfView_destroy(view);
    }

    SECTION("sfView_setScissor")
    {
        sfView* view = sfView_create();
        sfView_setScissor(view, {{0.75f, 0.25f}, {0, 0.5f}});
        const sfFloatRect scissor = sfView_getScissor(view);
        CHECK(scissor.position.x == 0.75f);
        CHECK(scissor.position.y == 0.25f);
        CHECK(scissor.size.x == 0);
        CHECK(scissor.size.y == 0.5f);
        sfView_destroy(view);
    }

    SECTION("sfView_move, sfView_rotate, sfView_zoom")
    {
        sfView* view = sfView_create();
        sfView_move(view, {15, 35});
        sfView_rotate(view, 180);
        sfView_zoom(view, 2);
        const sfVector2f center = sfView_getCenter(view);
        CHECK(center.x == 515);
        CHECK(center.y == 535);
        const sfVector2f size = sfView_getSize(view);
        CHECK(size.x == 2000);
        CHECK(size.y == 2000);
        CHECK(sfView_getRotation(view) == 180);
        const sfFloatRect viewport = sfView_getViewport(view);
        CHECK(viewport.position.x == 0);
        CHECK(viewport.position.y == 0);
        CHECK(viewport.size.x == 1);
        CHECK(viewport.size.y == 1);
        const sfFloatRect scissor = sfView_getScissor(view);
        CHECK(scissor.position.x == 0);
        CHECK(scissor.position.y == 0);
        CHECK(scissor.size.x == 1);
        CHECK(scissor.size.y == 1);
        sfView_destroy(view);
    }
}
