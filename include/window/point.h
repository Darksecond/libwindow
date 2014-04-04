#pragma once

namespace window
{
    template <typename T>
    struct point
    {
        inline point() : x(0), y(0)
        {
        }

        inline point(T x_, T y_) : x(x_), y(y_)
        {
        }

        inline point<T> operator+(const point<T>& other)
        {
            return point<T>(x+other.x, y+other.y);
        }

        inline point<T> operator-(const point<T>& other)
        {
            return point<T>(x-other.x, y-other.y);
        }

        inline void zero()
        {
            x = 0;
            y = 0;
        }

        T x;
        T y;
    };
}
