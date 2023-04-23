#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <vector>
#include <map>
#include <functional>
#include <new>

namespace Game
{
    template<typename T>
    class Coord
    {
    public:
        typedef T value_type;
        T row;
        T col;

        Coord(T t_row = {}, T t_col = {})
        {
            row = t_row;
            col = t_col;
        }
    };
//    template<typename T>
//    T
//    tabs(T x)
//    {
//        return (x >= 0) ? x : (-x);
//    }
    template<typename T>
    T
    dist(Coord<T> size, Coord<T> point1, Coord<T> point2)
    {
        auto diff_col = abs(point1.col - point2.col);
        auto diff_row = abs(point1.row - point2.row);
        auto max_shift_col = diff_row / 2;
        auto max_shift_row = diff_col / 2;
        T ans = 0;
        if (diff_row > diff_col) {
            ans += diff_row;
            if (max_shift_col < diff_col) {
                ans += diff_col - max_shift_col;
            }
        } else {
            ans += diff_col;
            if (max_shift_row < diff_row) {
                ans += diff_row - max_shift_row;
            }
        }
        return ans;
    }
}

int
main(void)
{
    auto size = Game::Coord<int>(5, 5);
    auto p1 = Game::Coord<int>(2, 0);
    auto p2 = Game::Coord<int>(0, 1);
//    for (int i = -10; i < 11; i++) {
//        std::cout << Game::myabs<int>(i) << std::endl;
//    }
    std::cout << Game::dist<int>(size, p1, p2) << std::endl;
    return 0;
}

