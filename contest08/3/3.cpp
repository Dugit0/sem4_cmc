#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <vector>
#include <map>
#include <functional>
#include <new>


class S
{
    int val;
    int end;
public:
    S()
    {
//        std::cout << __PRETTY_FUNCTION__ << std::endl;
        end = 0;
        if (!(std::cin >> val)) {
            end = 2;
        }
    }

    S(S &&other)
    {
//        std::cout << __PRETTY_FUNCTION__ << std::endl;
        end = 0;
        int buf;
        val = other.val;
        if (std::cin >> buf) {
            val += buf;
        } else {
            end = 1;
        }
    }

    ~S()
    {
//        std::cout << __PRETTY_FUNCTION__ << std::endl;
        if (end == 1) {
            std::cout << val << std::endl;
        }
    }

    operator bool()
    {
        return end == 0;
    }
};


//void
//func(S v)
//{
//    if (v) {
//        func(std::move(v));
//    }
//}
//
//int
//main()
//{
////    S a;
////    int b = a;
////    std::cout << "b = " << b << std::endl;
//
//    func(S());
//}


