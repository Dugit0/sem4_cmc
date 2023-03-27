#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <vector>
#include <map>
#include <functional>
#include <new>

template<typename I, typename F>
void
myapply(I begin, I end, F f)
{
    while (begin != end) {
        f(*begin);
        ++begin;
    }
}


template<typename I, typename F>
auto
myfilter2(I begin, I end, F f) {
    std::vector<std::reference_wrapper<typename std::iterator_traits<I>::value_type>> ans;
    for (auto it = begin; it != end; ++it) {
        if (f(*it)) {
            ans.push_back(*it);
        }
    }
    return ans;
}

//template<typename I, typename F>
//auto
//myfilter2(I begin, I end, F f) {
//    std::vector<std::reference_wrapper<typename I::value_type>> ans;
//    for (auto it = begin; it != end; ++it) {
//        if (f(*it)) {
//            ans.push_back(*it);
//        }
//    }
//    return ans;
//}


//bool
//myf(int x)
//{
//    return x > 5;
//}
//
//void
//myf2(int &x)
//{
//    x = x*2;
//}
//
//int
//main(void)
//{
//    int x = 2;
//    int &sx = x;
////    myf2(sx);
//    std::cout << x << std::endl;
//    std::vector<int> vec = {1, 3, 4, 8, 5, 2, 1, 99};
//    auto vec2 = myfilter2(vec.begin(), vec.end(), myf);
//    myapply(vec2.begin(), vec2.end(), myf);
//    for (auto i : vec2) {
//        std::cout << i << std::endl;
//    }
//    return 0;
//}

