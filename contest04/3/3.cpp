#include <iostream>
#include <vector>
#include <algorithm>


void
process(const std::vector<int> &v1, std::vector<int> &v2)
{
    std::vector<int> v1_cp;
    std::copy(v1.begin(), v1.end(), std::back_inserter(v1_cp));
    std::sort(v1_cp.rbegin(), v1_cp.rend());
    auto v3 = std::unique(v1_cp.begin(), v1_cp.end());
//    std::sort(v1_cp.rbegin(), v1_cp.rend());
    for (auto it1 = v1_cp.begin(); it1 < v3; it1++) {
        if (v2.begin() <= v2.begin() + *it1 && v2.begin() + *it1 < v2.end()) {
            v2.erase(v2.begin() + *it1);
        }
    }
}

//
//int
//main(void)
//{
//
//    return 0;
//}
//
