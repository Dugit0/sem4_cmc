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
    std::map<unsigned long long, std::map<unsigned long long, unsigned long long>> dict;

    unsigned long long cur_row = 0;
    unsigned long long cur_col = 0;
    unsigned long long cur_num = 0;
    bool flag_sum = false;
    while (std::cin >> cur_row) {
        std::cin >> cur_col;
        std::cin >> cur_num;
        if (cur_row == 0 && cur_col == 0 && cur_num == 4294967161) {
            flag_sum = true;
        }
        if (flag_sum) {
            if (dict.find(cur_row) == dict.end() || dict[cur_row].find(cur_col) == dict[cur_row].end()) {
                dict[cur_row][cur_col] = cur_num % MOD;
            } else {
                dict[cur_row][cur_col] = (dict[cur_row][cur_col] + cur_num) % MOD;
            }
        } else {
            dict[cur_row][cur_col] = cur_num % MOD;
        }
    }

    for (auto i = dict.begin(); i != dict.end(); i++) {
        for (auto j = i->second.begin(); j != i->second.end(); j++) {
            if (j->second != 0) {
                std::cout << i->first << " " << j->first << " " << j->second << std::endl;
            }
        }
    }

    return 0;
}

