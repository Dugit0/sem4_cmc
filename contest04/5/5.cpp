#include <iostream>
#include <iomanip>
#include <list>
#include <iterator>
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
    std::list<unsigned int> my_list{};
    unsigned int buf;
    while (std::cin >> buf) {
        if (buf == 0) {
            break;
        }
        my_list.push_back(buf);
    }

    int instr;
    while (std::cin >> instr) {
        if (instr < 0) {
            instr = (-instr) - 1;
            if ((unsigned int) instr < my_list.size()) {
                auto rm_it = my_list.begin();
                std::advance(rm_it, instr);
                my_list.erase(rm_it);
            }
        } else if (instr > 0) {
            unsigned int value;
            std::cin >> value;
            instr--;
            if ((unsigned int) instr >= my_list.size()) {
                my_list.push_back(value);
            } else {
                auto in_it = my_list.begin();
                std::advance(in_it, instr);
                my_list.insert(in_it, value);
            }
        }
    }
    for (auto el : my_list) {
        std::cout << el << std::endl;
    }
    return 0;
}

