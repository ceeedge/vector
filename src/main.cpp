#include <fmt/core.h>

#include "vec.hpp"


constexpr auto runTests() -> void
{
    using namespace harp;
    static_assert(cross(vec3i{2, 3, 4}, vec3i{5, 6, 7}) == vec3i{-3, 6, -3});
    static_assert(dot(vec3i{9, 2, 7}, vec3i{4, 8, 10}) == 122);
}

int main()
{
    runTests();
    fmt::print("Testing completed\n");
    return 0;
}