Vector2.h 
  #pragma once
#include <iostream>

struct Vector2
{
    float x;
    float y;

    float& operator[](int i);
    const float& operator[](int i) const;

    Vector2& operator*=(float a);
    Vector2& operator/=(float a);
    Vector2& operator+=(const Vector2& w);
    Vector2& operator-=(const Vector2& w);
};

Vector2 operator*(const Vector2& v, float a);
Vector2 operator*(float a, const Vector2& v);
Vector2 operator/(const Vector2& v, float a);
Vector2 operator+(const Vector2& v, const Vector2& w);
Vector2 operator-(const Vector2& v, const Vector2& w);
std::ostream& operator<<(std::ostream& os, const Vector2& v);

Vector2.cpp
  #include "Vector2.h"

float& Vector2::operator[](int i)
{
    return i == 0 ? x : y;
}

const float& Vector2::operator[](int i) const
{
    return i == 0 ? x : y;
}

Vector2& Vector2::operator*=(float a)
{
    x *= a;
    y *= a;
    return *this;
}

Vector2& Vector2::operator/=(float a)
{
    x /= a;
    y /= a;
    return *this;
}

Vector2& Vector2::operator+=(const Vector2& w)
{
    x += w.x;
    y += w.y;
    return *this;
}

Vector2& Vector2::operator-=(const Vector2& w)
{
    x -= w.x;
    y -= w.y;
    return *this;
}

Vector2 operator*(const Vector2& v, float a)
{
    return Vector2{ v.x * a, v.y * a };
}

Vector2 operator*(float a, const Vector2& v)
{
    return Vector2{ v.x * a, v.y * a };
}

Vector2 operator/(const Vector2& v, float a)
{
    return Vector2{ v.x / a, v.y / a };
}

Vector2 operator+(const Vector2& v, const Vector2& w)
{
    return Vector2{ v.x + w.x, v.y + w.y };
}

Vector2 operator-(const Vector2& v, const Vector2& w)
{
    return Vector2{ v.x - w.x, v.y - w.y };
}

std::ostream& operator<<(std::ostream& os, const Vector2& v)
{
    os << "(" << v.x << ", " << v.y << ")";
    return os;
}

main.cpp
  #include <cassert>
#include "Vector2.h"

int main()
{
    Vector2 a{1, 2};
    Vector2 b{3, 4};

    assert((a * 2).x == 2 && (a * 2).y == 4);
    assert((2 * a).x == 2 && (2 * a).y == 4);
    assert((b / 2).x == 1.5f && (b / 2).y == 2.0f);

    Vector2 c = a;
    c *= 3;
    assert(c.x == 3 && c.y == 6);

    c = b;
    c /= 2;
    assert(c.x == 1.5f && c.y == 2.0f);

    assert((a + b).x == 4 && (a + b).y == 6);
    assert((b - a).x == 2 && (b - a).y == 2);

    c = a;
    c += b;
    assert(c.x == 4 && c.y == 6);

    c += b;
    assert(c.x == 7 && c.y == 10);

    c = b;
    c -= a;
    assert(c.x == 2 && c.y == 2);

    assert(a[0] == 1 && a[1] == 2);
    a[0] = 10;
    assert(a.x == 10);

    return 0;
}
