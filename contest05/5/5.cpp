#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>
#include <string>
#include <set>

const unsigned long long MOD = 4294967161;

int
main(void)
{
    std::map<unsigned int, std::map<unsigned int, unsigned long long>> dict1;
    std::map<unsigned int, std::map<unsigned int, unsigned long long>> dict2;

    unsigned int cur_row = 0;
    unsigned int cur_col = 0;
    unsigned long long cur_num = 0;
    bool flag_mul = false;
    while (std::cin >> cur_row) {
        std::cin >> cur_col;
        std::cin >> cur_num;
        if (cur_row == 0 && cur_col == 0 && cur_num == 4294967161) {
            flag_mul = true;
        }
        if (flag_mul) {
            if (dict1.find(cur_row) != dict1.end()) {
                for (auto i = dict1[cur_row].begin(); i != dict1[cur_row].end(); i++) {
                    dict2[i->first][cur_col] = (dict2[i->first][cur_col] + i->second * cur_num) % MOD;
                }
            }
        } else {
            dict1[cur_col][cur_row] = cur_num % MOD;
        }
    }
//    std::cout << "Fin inp" << std::endl;
//    for (auto i = dict1.begin(); i != dict1.end(); i++) {
//        for (auto j = dict2.begin(); j != dict2.end(); j++) {
////            std::cout << i->first << " " << j->first << std::endl;
//            auto str_it = i->second.begin();
//            auto col_it = j->second.begin();
//            unsigned long long ans = 0;
//            while (str_it != i->second.end() && col_it != j->second.end()) {
//                if (str_it->first == col_it->first) {
//                    unsigned long long tmp = (str_it->second * col_it->second) % MOD;
//                    ans = (ans + tmp) % MOD;
//                    str_it++;
//                    col_it++;
//                } else if (str_it->first < col_it->first) {
//                    str_it++;
//                } else if (str_it->first > col_it->first) {
//                    col_it++;
//                }
//            }
    for (auto i = dict2.begin(); i != dict2.end(); i++) {
        for (auto j = i->second.begin(); j != i->second.end(); j++) {
            if (j->second != 0) {
                std::cout << i->first << " " << j->first << " " << j->second << std::endl;
            }
        }
    }

    return 0;
}


