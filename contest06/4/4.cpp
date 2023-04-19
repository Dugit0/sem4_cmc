#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <vector>
#include <map>
#include <functional>
#include <new>


template<typename Iter_Num, typename Iter_Val>
auto
myremove(Iter_Num begin_num, Iter_Num end_num, Iter_Val begin, Iter_Val end)
{
    std::vector v1_cp(begin_num, end_num);
    std::sort(v1_cp.begin(), v1_cp.end());
    auto new_end_num = std::unique(v1_cp.begin(), v1_cp.end());
    auto new_begin_num = v1_cp.begin();
    while (*new_begin_num < 0) {
        new_begin_num++;
        if (new_begin_num == new_end_num) {
            break;
        }
    }
    long long cur_num = 0;
    auto cur_val_it = begin;
    auto cur_last_it = begin;
    while (cur_val_it != end) {
        if (new_begin_num != new_end_num && cur_num == *new_begin_num) {
            new_begin_num++;
            cur_num++;
            cur_val_it++;
        } else {
            *cur_last_it = std::move(*cur_val_it);
            cur_last_it++;
            cur_num++;
            cur_val_it++;
        }
    }
    return cur_last_it;
}

//int
//main(void)
//{
//
//    return 0;
//}

