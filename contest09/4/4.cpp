#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <vector>
#include <map>
#include <functional>
#include <new>

/*
S -> aAd
A -> aAd | bBc
B -> bBc | eps
*/

void
B(size_t cur, size_t k)
{
    if (cur + 2 <= k) {
        std::cout << "b";
        B(cur + 2, k);
        std::cout << "c";
    }
}

void
A(size_t cur, size_t k)
{
    if (cur + 2 <= k - 2) {
        std::cout << "a";
        A(cur + 2, k);
        std::cout << "d";
        std::cout << "b";
        B(cur + 2, k);
        std::cout << "c";
    } else if (cur + 2 <= k) {
        std::cout << "b";
        B(cur + 2, k);
        std::cout << "c";
    }
}


void
S(size_t k)
{
    std::cout << "a";
    A(2, k);
    std::cout << "d" << std::endl;
}


int
main(void)
{
//    int k;
//    std::cin >> k;
    int k = 6;
    S(k);
    return 0;
}

