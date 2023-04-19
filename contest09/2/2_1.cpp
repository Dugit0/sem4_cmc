#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <vector>
#include <map>
#include <functional>
#include <new>


unsigned int
my_find(std::string s)
{
    unsigned int count = 0;
    int flag0 = 0;
    for (; count < s.size(); count++) {
        flag0 = 1;
        if (s[count] != '0') {
            break;
        }
    }
    int flag1 = 0;
    for (; count < s.size(); count++) {
        flag1 = 1;
        if (s[count] != '1') {
            break;
        }
    }
    if (flag0 == 0 || flag1 == 0) {
        return 0;
    }
    return count;
}

int
check(std::string s)
{
    unsigned int my_len = my_find(s);
    if (my_len == 0) {
        return 0;
    }
//    std::cout << my_len << std::endl;
    if (s.size() % my_len != 0) {
        return 0;
    }
    int flag = 0;
    for (unsigned int time = 0; time < s.size() / my_len; time++) {
        flag = 1;
        for (unsigned int i = 0; i < my_len; i++) {
            if (s[i] != s[time * my_len + i]) {
                return 0;
            }
        }
    }
    if (flag == 0) {
        return 0;
    }
    return 1;
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
