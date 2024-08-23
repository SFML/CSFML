#include <CSFML/System/Buffer.h>

#include <catch2/catch_test_macros.hpp>

TEST_CASE("[System] sfBuffer")
{
    sfBuffer* buffer = sfBuffer_create();
    CHECK(sfBuffer_getSize(buffer) == 0);
    CHECK(sfBuffer_getData(buffer) == 0);
    sfBuffer_destroy(buffer);
}
