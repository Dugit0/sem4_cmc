#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <vector>
#include <map>
#include <functional>
#include <new>

//template<typename T>
//bool
//default_comp(const T &f, const T &s)
//{
//    return (f < s);
//}

//bool
//default_comp(const int &f, const int &s)
//{
//    return (f < s);
//}

template<typename Iter>
void
selection_sort(
        Iter begin,
        Iter end,
        std::function<bool(
                const typename std::iterator_traits<Iter>::value_type &,
                const typename std::iterator_traits<Iter>::value_type &)>
        comp = [](
                const typename std::iterator_traits<Iter>::value_type &f,
                const typename std::iterator_traits<Iter>::value_type &s) { return f < s; }
)
{
//    for (auto i = begin; i != end; i++) {
//        auto min = i;
//        for (auto j = i; j != end; j++) {
//            if (comp(*j, *min)) {
//                min = j;
//            }
//        }
//        std::swap(*i, *min);
//    }
    auto i = begin;
    while (i != end) {
        auto j = i;
        auto min = j;
        while (j != end) {
            if (comp(*j, *min)) {
                min = j;
            }
            j++;
        }
        std::swap(*i, *min);
        i++;
    }
}


//int
//main(void)
//{
//    std::vector<int> a = { 2, 3, 4, 1, 7, 6, 5, 9, 8, 10 };
//    selection_sort(a.begin(), a.end());
//    for (auto el: a) {
//        std::cout << el << " ";
//    }
//    return 0;
//}

