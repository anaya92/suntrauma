#pragma once

namespace Math
{
    template<typename T>
    struct Vector2
    {
        union
        {
            struct 
            {
                T x, y;
            };

            struct 
            {
                T w, h;
            };
            
            struct 
            {
                T s, t;
            };
        };

        Vector2<T> operator+(Vector2<T> two)
        {
            Vector2<T> fin;
            fin.x = x + two.x;
            fin.y = y + two.y;

            return fin;
        }

        Vector2<T> operator-(Vector2<T> two)
        {
            Vector2<T> fin;
            fin.x = x - two.x;
            fin.y = y - two.y;

            return fin;
        }

        Vector2<T> operator*(Vector2<T> two)
        {
            Vector2<T> fin;
            fin.x = x * two.x;
            fin.y = y * two.y;

            return fin;
        }

        Vector2<T> operator/(Vector2<T> two)
        {
            Vector2<T> fin;
            fin.x = x / two.x;
            fin.y = y / two.y;

            return fin;
        }

        bool operator==(Vector2<T> v)
        {
            return (v.x == x) && (v.y == y);
        }

        Vector2(T x, T y) : x(x), y(y) {}
        Vector2(T x) : x(x), y(x) {}
        Vector2() : x(0), y(0) {}
    };

    template<typename T>
    struct Vector3
    {
        union
        {
            struct
            {
                T x, y, z;
            };

            struct
            {
                T s, t, w;
            };
        };

        Vector3<T> operator+(Vector3<T> two)
        {
            Vector3<T> fin;
            fin.x = x + two.x;
            fin.y = y + two.y;
            fin.z = z + two.z;

            return fin;
        }

        Vector3<T> operator-(Vector3<T> two)
        {
            Vector3<T> fin;
            fin.x = x - two.x;
            fin.y = y - two.y;
            fin.z = z - two.z;

            return fin;
        }

        Vector3<T> operator*(Vector3<T> two)
        {
            Vector3<T> fin;
            fin.x = x * two.x;
            fin.y = y * two.y;
            fin.z = z * two.z;

            return fin;
        }

        Vector3<T> operator/(Vector3<T> two)
        {
            Vector3<T> fin;
            fin.x = x / two.x;
            fin.y = y / two.y;
            fin.z = z / two.z;

            return fin;
        }

        bool operator==(Vector3<T> v)
        {
            return (v.x == x) && (v.y == y) && (v.z == z);
        }

        Vector3(T x, T y, T z) : x(x), y(y), z(z) {}
        Vector3(T x) : x(x), y(x), z(x) {}
        Vector3() : x(0), y(0), z(0) {}
    };

    typedef Vector2<double> Vector2d;
    typedef Vector3<double> Vector3d;

    typedef Vector2<float> Vector2f;
    typedef Vector3<float> Vector3f;
}
