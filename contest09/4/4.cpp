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
B(int gen1, int gen2)
{
    if (gen2 > 0) {
        std::cout << "b";
        B(0, gen2 - 1);
        std::cout << "c";
    }
}

void
A(int gen1, int gen2)
{
    if (gen1 > 0) {
        std::cout << "a";
        A(gen1 - 1, gen2);
        std::cout << "d";
    } else {
        std::cout << "b";
        B(0, gen2 - 1);
        std::cout << "c";
    }
}


void
S(int gen1, int gen2)
{
    std::cout << "a";
    A(gen1 - 1, gen2);
    std::cout << "d";
}


void
f(int gen1, int gen2)
{
    if (gen2 > 1) {
        f(gen1 + 1, gen2 - 1);
    }
//    std::cout << gen1 << " " << gen2 << std::endl;
    S(gen1, gen2);
    std::cout << std::endl;
}


int
main(void)
{
    int k;
    std::cin >> k;
//    int k = 8;
    if (k < 4 || k % 2 == 1) {
        return 0;
    }
    f(1, k / 2 - 1);
    return 0;
}

