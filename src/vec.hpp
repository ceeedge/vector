#pragma once

#include <cmath>
#include <concepts>

template<typename T>
requires std::integral<T> || std::floating_point<T>
struct Vec2 
{
    T x1 = 0, x2 = 0;
    constexpr Vec2<T>() = default;
    constexpr Vec2<T>(T x1_, T x2_) : x1{x1_}, x2{x2_} {}

    constexpr auto operator+=(Vec2<T> rhs) const
    {
        return Vec2<T>(x1+rhs.x1, x2+rhs.x2);
    }

    constexpr auto operator-=(Vec2<T> rhs) const
    {
        return Vec2<T>(x1-rhs.x1, x2-rhs.x2);
    }

    constexpr auto operator-() const
    {
        return Vec2<T>(-x1, -x2);
    }

    template<typename U>
    requires std::integral<U> || std::floating_point<U>
    constexpr auto operator*=(U rhs) const
    {
        return Vec2<T>(x1*rhs, x2*rhs);
    } 

    constexpr auto magnitude() const
    {
        return std::sqrt(x1^2 + x2^2);
    }
};

template<typename T>
requires std::integral<T> || std::floating_point<T>
constexpr auto dot(Vec2<T> lhs, Vec2<T> rhs)
{
    return(lhs.x1*rhs.x1+lhs.x2*rhs.x2)
}

using vec2i = Vec2<int>;
using vec2u = Vec2<unsigned int>;
using vec2f = Vec2<float>;

