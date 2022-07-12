#pragma once

#include <cmath>
#include <concepts>

namespace harp {

template<typename T>
concept numeric = std::integral<T> || std::floating_point<T>;

template<typename T>
requires numeric<T>
struct Vec2
{
  T x = 0, y = 0;
  constexpr Vec2<T>() = default;
  constexpr Vec2<T>(T x_, T y_) : x{ x_ }, y{ y_ } {}

  constexpr auto operator+=(Vec2<T> rhs) const { return Vec2<T>{ x + rhs.x, y + rhs.y }; }

  constexpr auto operator-=(Vec2<T> rhs) const { return Vec2<T>{ x - rhs.x, y - rhs.y }; }

  constexpr auto operator-() const { return Vec2<T>{ -x, -y }; }

  template<typename U>
  requires numeric<U>
  constexpr auto operator*=(U rhs) const { return Vec2<T>{ x * rhs, y * rhs }; }

  constexpr auto operator<=>(const Vec2<T> &) const = default;

  constexpr auto magnitude() const { return std::sqrt(x ^ 2 + y ^ 2); }
};

template<typename T>
requires numeric<T>
constexpr auto dot(const Vec2<T> &lhs, const Vec2<T> &rhs) { return (lhs.x * rhs.x + lhs.y * rhs.y); }

using vec2i = Vec2<int>;
using vec2u = Vec2<unsigned int>;
using vec2f = Vec2<float>;


template<typename T>
requires numeric<T>
struct Vec3
{
  T x = 0, y = 0, z = 0;

  constexpr Vec3<T>() = default;
  constexpr Vec3<T>(T x_, T y_, T z_) : x{ x_ }, y{ y_ }, z{ z_ } {}

  constexpr auto operator+=(Vec3<T> rhs) const { return Vec3<T>{ x + rhs.x, y + rhs.y, z + rhs.z }; }
  constexpr auto operator-=(Vec3<T> rhs) const { return Vec3<T>{ x - rhs.x, y - rhs.y, z - rhs.z }; }
  constexpr auto operator-() const { return Vec3<T>{ -x, -y, -z }; }

  constexpr auto operator<=>(const Vec3<T> &) const = default;

  constexpr auto magnitude() const { return std::sqrt(x ^ 2 + y ^ 2 + z ^ 2); }

  template<typename U>
  requires numeric<U>
  constexpr auto operator*=(U rhs) { return Vec3<T>{ x * rhs, y * rhs, z * rhs }; }
};

template<typename T>
requires numeric<T>
constexpr auto dot(const Vec3<T> &lhs, const Vec3<T> &rhs) { return (lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z); }

template<typename T>
requires numeric<T>
constexpr auto cross(const Vec3<T> &lhs, const Vec3<T> &rhs)
{
  return Vec3<T>{ lhs.y * rhs.z - lhs.z * rhs.y, lhs.z * rhs.x - lhs.x * rhs.z, lhs.x * rhs.y - lhs.y * rhs.x };
}

using vec3i = Vec3<int>;
using vec3f = Vec3<float>;
using vec3u = Vec3<unsigned int>;

}// namespace harp