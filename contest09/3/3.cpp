#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <vector>
#include <map>
#include <functional>
#include <new>


// a^n 0^m b^n 1^m
// n, m > 0

// КЗ-грамматика
// S -> LD
// L -> aLb | ab
// D -> ND1 | N1
// bN -> Nb
// aN -> a0
// 0N -> 00

int
check(std::string str)
{
    auto i = str.begin();
    int status = 1;
    size_t a_counter = 0;
    size_t b_counter = 0;
    size_t null_counter = 0;
    size_t ones_counter = 0;
    while (i != str.end()) {
        switch (status) {
            case 1:
                if (*i != 'a') {
                    if (*i != '0') {
                        return 0;
                    } else {
                        status++;
                    }
                } else {
                    a_counter++;
                    i++;
                }
                break;
            case 2:
                if (*i != '0') {
                    if (*i != 'b') {
                        return 0;
                    } else {
                        status++;
                    }
                } else {
                    null_counter++;
                    i++;
                }
                break;
            case 3:
                if (*i != 'b') {
                    if (*i != '1') {
                        return 0;
                    } else {
                        status++;
                    }
                } else {
                    b_counter++;
                    i++;
                }
                break;
            case 4:
                if (*i != '1') {
                    return 0;
                } else {
                    ones_counter++;
                    i++;
                }
                break;
        }
    }
    return (a_counter == b_counter && null_counter == ones_counter);
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

