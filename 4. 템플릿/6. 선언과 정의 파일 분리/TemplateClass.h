#pragma once

template <typename T>
class Point
{
    T x, y;

public:
    Point(T x, T y);

    T Func(const T& ref);
};
