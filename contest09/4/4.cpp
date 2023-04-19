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
main(void)
{
    int k;
    std::cin >> k;
    if (k >= 4 && k % 2 == 0) {
        for (int n = 1; n < k / 2; n++) {
            for (int i = 0; i < n; i++) {
                std::cout << "a";
            }
            for (int i = 0; i < k / 2 - n; i++) {
                std::cout << "b";
            }
            for (int i = 0; i < k / 2 - n; i++) {
                std::cout << "c";
            }
            for (int i = 0; i < n; i++) {
                std::cout << "d";
            }
            std::cout << std::endl;
        }
    }
    
    return 0;
}

