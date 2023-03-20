#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>
#include <string>
#include <set>


int
main(void)
{
    unsigned long long max_row = 0;
    unsigned long long max_col = 0;
    std::map<unsigned long long, std::map<unsigned long long, unsigned long long>> dict;

    unsigned long long cur_row = 0;
    unsigned long long cur_col = 0;
    unsigned long long cur_num = 0;
    while (std::cin >> cur_row) {
        std::cin >> cur_col;
        std::cin >> cur_num;
        dict[cur_row][cur_col] = cur_num;
        max_row = std::max(max_row, cur_row);
        max_col = std::max(max_col, cur_col);
    }

    for (unsigned long long i = 0; i < max_row; i++) {
        for (unsigned long long j = 0; j < max_col; j++) {
           if (dict.find(i) == dict.end() || dict[i].find(j) == dict[i].end()) {
               std::cout << "0 ";
           } else {
               std::cout << dict[i][j] << " ";
           }
        }
        std::cout << std::endl;
    }

    return 0;
}

