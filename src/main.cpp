#include <fmt/core.h>

#include "vec.hpp"


int main()
{
    Vec2<int> v1{1, 2};
    Vec2<int> v2{3, 4};
    auto v3 = -v2;
    auto m = v2.magnitude();
    fmt::print("{}\n", m);

    return 0;
}