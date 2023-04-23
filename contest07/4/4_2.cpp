#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <vector>
#include <map>
#include <functional>
#include <new>

// Solution based on
// https://www.redblobgames.com/grids/hexagons/

namespace Game
{
    template<typename T>
    class Coord
    {
    public:
        typedef T value_type;
        T col;
        T row;

        Coord(T t_col = {}, T t_row = {})
        {
            col = t_col;
            row = t_row;
        }
    };

    template<typename T>
    class Cube
    {
    public:
        typedef T value_type;
        T q;
        T r;
        T s;

        Cube(T t_q = {}, T t_r = {}, T t_s = {})
        {
            q = t_q;
            r = t_r;
            s = t_s;
        }
    };

    template<typename T>
    Cube<T>
    evenq_to_cube(Coord<T> hex)
    {
        T q = hex.col;
        T r = hex.row - (hex.col + (hex.col & 1)) / 2;
        return Cube(q, r, -q - r);
    }

//    template<typename T>
//    Coord<T>
//    cube_to_evenq(Cube<T> hex)
//    {
//        T col = hex.q;
//        T row = hex.r + (hex.q + (hex.q & 1)) / 2;
//        return Coord(col, row);
//    }

    template<typename T>
    T
    max(T a, T b, T c)
    {
        if (a >= b && a >= c) {
            return a;
        } else if (b >= c) {
            return b;
        } else {
            return c;
        }
    }

    template<typename T>
    T
    dist(Coord<T> size, Coord<T> point1, Coord<T> point2)
    {
        Cube<T> a = evenq_to_cube(point1);
        Cube<T> b = evenq_to_cube(point2);
        return Game::max(std::abs(a.q - b.q), std::abs(a.r - b.r), std::abs(a.s - b.s));
    }
}

int
main(void)
{
    auto size = Game::Coord<int>(5, 5);
    auto p1 = Game::Coord<int>(0, 2);
    auto p2 = Game::Coord<int>(1, 0);
//    for (int i = -10; i < 11; i++) {
//        std::cout << Game::myabs<int>(i) << std::endl;
//    }
    std::cout << Game::dist<int>(size, p1, p2) << std::endl;
    return 0;
}

