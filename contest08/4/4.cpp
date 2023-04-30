#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <vector>
#include <map>
#include <functional>
#include <new>
#include <complex>
#include <array>

namespace Equations
{
    template<class T>
    bool
    cmp_with_null(std::complex<T> x)
    {
        return std::norm(x) < 32 * std::numeric_limits<T>::epsilon();
    }

    template<class T>
    std::pair<bool, std::vector<std::complex<T>>>
    quadratic(std::array<std::complex<T>, 3> v)
    {
        if (cmp_with_null(v[0]) && cmp_with_null(v[1]) && cmp_with_null(v[2])) {
            return {false, {}};
        } else if (cmp_with_null(v[1]) && cmp_with_null(v[2])) {
            return {true, {}};
        } else if (cmp_with_null(v[2])) {
            auto x = -(v[0] / v[1]);
            return {true, {x}};
        } else {
            auto D = v[1] * v[1] - T(4) * v[2] * v[0];
            auto x1 = (-v[1] + std::sqrt(D)) / (T(2) * v[2]);
            auto x2 = (-v[1] - std::sqrt(D)) / (T(2) * v[2]);
            return {true, {x1, x2}};
        }
    }
}

//int
//main()
//{
//    std::array<std::complex<double>, 3> v1{
//            std::complex<double>(0, 0),
//            std::complex<double>(0, 0),
//            std::complex<double>(0, 0)
//    };
//
//    auto res = Equations::quadratic(v1);
//    std::cout << res.first << std::endl;
//    if (res.first) {
//        for (auto i : res.second) {
//            std::cout << i.real() << " " << i.imag() << std::endl;
//        }
//    }
//}


