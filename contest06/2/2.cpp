#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <vector>
#include <map>
#include <functional>
#include <new>

template<typename T, typename P>
auto
myfilter(T cont, P pred)
{
    T my_cont = {};
    for (auto it = cont.begin(); it != cont.end(); ++it) {
        if (pred(*it)) {
            my_cont.insert(my_cont.end(), *it);
        }
    }
    return my_cont;
}

//bool
//myf(int x)
//{
//    return x > 5;
//}
//
//int
//main(void)
//{
//    std::vector<int> vec = {1, 3, 4, 8, 5, 2, 1, 99};
//    auto ans = myfilter(vec, myf);
//    for (auto i : ans) {
//        std::cout << i << std::endl;
//    }
//    return 0;
//}

