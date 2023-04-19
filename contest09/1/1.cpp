#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <vector>
#include <map>
#include <functional>
#include <new>

int
check(std::string s)
{
    size_t count = 0;
    for (; count < s.size(); count++) {
//        std::cout << count << "c" << std::endl;
        if (s[count] != '3' && s[count] != '4') {
            break;
        }
    }
    for (; count < s.size(); count++) {
        if (s[count] != '1' && s[count] != '2') {
            break;
        }
    }
    if (count == s.size()) {
        return 1;
    } else {
        return 0;
    }
}

int
main(void)
{
    std::string buf;
    while (std::cin >> buf) {
        std::cout << check(buf) << std::endl;
    }
    
    return 0;
}

