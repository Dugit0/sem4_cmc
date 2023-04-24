#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <new>



int
main(void)
{
    std::vector<std::pair<char, std::string>> gram = {};
    char buf_left;
    std::string buf_right;
    std::set<char> unused_sym = {};
    std::set<char> used_syms = {};
    while (std::cin >> buf_left >> buf_right) {
        std::pair<char, std::string> buf_pair{buf_left, buf_right};
        gram.push_back(buf_pair);
    }
    used_syms.insert('S');
    while (true) {
//        std::cout << "deb ";
//        for (auto i : used_syms) {
//            std::cout << i << " ";
//        }
//        std::cout << std::endl;

        std::set<char> new_used_syms = {};
        for (auto el : gram) {
            if (used_syms.find(el.first) != used_syms.end()) {
                for (auto new_used_sym : el.second) {
                    if (std::isupper(new_used_sym)) {
                        new_used_syms.insert(new_used_sym);
                    }
                }
            }
        }
        size_t old_size = used_syms.size();
        for (auto new_used_sym : new_used_syms) {
            used_syms.insert(new_used_sym);
        }
        if (old_size == used_syms.size()) {
            break;
        }
    }


    for (auto el : gram) {
        if (used_syms.find(el.first) != used_syms.end()) {
            std::cout << el.first << " " << el.second << std::endl;
        }
    }
    return 0;
}

