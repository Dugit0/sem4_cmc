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
    std::map<std::string, std::map<char, std::string>> rules = {};
    std::string cur_buf, char_buf, new_buf;
    std::cin >> cur_buf;
    while (cur_buf != "END") {
        std::cin >> char_buf >> new_buf;
        rules[cur_buf][char_buf[0]] = new_buf;
        std::cin >> cur_buf;
    }
//    for (auto el : rules) {
//        std::cout << el.first << std::endl;
//        for (auto el0 : el.second) {
//            std::cout << "    " << el0.first << " " << el0.second << std::endl;
//        }
//    }
    std::vector<std::string> end_vec = {};
    std::cin >> cur_buf;
    while (cur_buf != "END") {
        end_vec.push_back(cur_buf);
        std::cin >> cur_buf;
    }
    std::string begin_str, end_str;
    std::cin >> begin_str >> end_str;
    size_t i = 0;
    bool flag_break = false;
    for (i = 0; i < end_str.size(); i++) {
        if (rules[begin_str].find(end_str[i]) == rules[begin_str].end()) {
            flag_break = true;
            std::cout << 0 << std::endl << i << std::endl << begin_str << std::endl;
            break;
        }
        begin_str = rules[begin_str][end_str[i]];
    }
    if (!flag_break) {
        bool flag_end = false;
        for (size_t j = 0; j < end_vec.size(); j++) {
            if (begin_str == end_vec[j]) {
                flag_end = true;
                break;
            }
        }
        if (flag_end) {
            std::cout << 1 << std::endl << end_str.size() << std::endl << begin_str << std::endl;
        } else {
            std::cout << 0 << std::endl << end_str.size() << std::endl << begin_str << std::endl;
        }
    }
    return 0;
}

