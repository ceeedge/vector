#include <fmt/core.h>

#include "vec.hpp"


int main()
{
    Vec2<int> v1{1, 2};
    Vec2<int> v2{3, 4};
    auto v3 = -v2;
    auto m = v2.magnitude();
    constexpr auto prod = cross(vec3i{2, 3, 4}, vec3i{5, 6, 7});
    fmt::print("{},{},{}\n", prod.x, prod.y, prod.z);
    constexpr auto dprod = dot(vec3i{9, 2, 7}, vec3i{4, 8, 10});
    fmt::print("{}\n", dprod);
    return 0;
}