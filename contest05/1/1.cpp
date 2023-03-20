#include <iostream>
#include <vector>
#include <algorithm>

const unsigned int NUM_UINT_BIT = 32;

unsigned int
count_ones(unsigned int x)
{
    unsigned int ans = 0;
    for (unsigned int shift = 0; shift < NUM_UINT_BIT; shift++) {
        if ((x >> shift) & 1) {
            ans++;
        }
    }
    return ans;
}

bool
cmp(const unsigned int &a, const unsigned int &b)
{
    return count_ones(a) < count_ones(b);
}


int
main(void)
{
    std::vector<unsigned int> vec;
    unsigned int buf;
    while (std::cin >> buf) {
        vec.push_back(buf);
    }
    std::stable_sort(vec.begin(), vec.end(), cmp);

    for (auto i : vec) {
        std::cout << i << std::endl;
    }

    return 0;
}

