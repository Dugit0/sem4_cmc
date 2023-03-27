#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <vector>
#include <map>
#include <functional>
#include <new>

template<typename T>
auto
process(T container)
{
    typename T::value_type ans = {};
    if (container.begin() == container.end()) {
        return ans;
    }
    auto iterat = container.rbegin();
    ans += *iterat;
    int count = 0;
    while (iterat != container.rend()) {
        if (count == 2 || count == 4) {
            ans += *iterat;
        }
        count++;
        ++iterat;
        if (count > 4) {
            break;
        }
    }
    return ans;
}

//int
//main(void)
//{
//    std::vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7};
//    std::cout << process(vec) << std::endl;
//    return 0;
//}

