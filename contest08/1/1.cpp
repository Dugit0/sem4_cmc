#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <vector>
#include <map>
#include <functional>
#include <new>


const int END = 1;

class My_exception
{
public:
    bool flag_null = false;
    std::string str;


    My_exception(const std::string &s) : str(std::move(s))
    {
    }

    ~My_exception()
    {
        if (!flag_null) {
            std::cout << str << std::endl;
        }
    }
};


void my_func()
{
    std::string str;
    try {
        if (std::cin >> str) {
            my_func();
            My_exception tmp(str);
        }
        throw END;
    } catch (...) {
    }
//    std::string str;
//    if (!(std::cin >> str)) {
//        throw END;
//    } else {
//        try {
//            My_exception tmp(str);
//            my_func();
//        } catch (...) {
//            throw END;
//        }
//    }
}

int
main(void)
{
    try {
        my_func();
    } catch (...) {
    }
    return 0;
}

