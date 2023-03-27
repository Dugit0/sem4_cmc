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


template<typename I, typename F>
void
myremove(I begin_num, I end_num, I begin, I end)
{
    std::vector<int> v1_cp;
    std::copy(v1.begin(), v1.end(), std::back_inserter(v1_cp));
    std::sort(v1_cp.rbegin(), v1_cp.rend());
    auto v3 = std::unique(v1_cp.begin(), v1_cp.end());
//    std::sort(v1_cp.rbegin(), v1_cp.rend());
    for (auto it1 = v1_cp.begin(); it1 < v3; it1++) {
        if (v2.begin() <= v2.begin() + *it1 && v2.begin() + *it1 < v2.end()) {
            v2.erase(v2.begin() + *it1);
        }
    }
}

int
main(void)
{
    
    return 0;
}

