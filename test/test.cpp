#include "vec.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE( "Vec3", "[vec3i]")
{
    using namespace harp;
    REQUIRE( cross(vec3i{2, 3, 4}, vec3i{5, 6, 7}) == vec3i{-3, 6, -3} );
    REQUIRE( dot(vec3i{9, 2, 7}, vec3i{4, 8, 10}) == 122);
}