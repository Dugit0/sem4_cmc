#include <iostream>
#include <vector>
#include <cstdint>


void
process(std::vector<int64_t> &vec1, int64_t lim)
{
    unsigned int add_cont = 0;
    for (auto iter = vec1.begin(); iter < vec1.end(); iter++) {
        if (*iter >= lim) {
            add_cont++;
        }
    }
    for (unsigned int i = 0; i < add_cont; i++) {
        vec1.push_back(0);
    }

    auto cur_pos = vec1.end() - add_cont;
//    std::cout << *cur_pos << std::endl;
    for (auto iter = vec1.rbegin() + add_cont; iter < vec1.rend(); iter++) {
//        std::cout << *iter << std::endl;
        if (*iter >= lim) {
            *cur_pos = *iter;
            cur_pos++;
        }
//        for (auto i: vec1) {
//            std::cout << i << " ";
//        }
//        std::cout << std::endl;
    }
}


//
//int
//main(void)
//{
//    std::vector<int64_t> v1 = {1, 4, 3, 2};
//    process(v1, 3);
//    std::cout << "meow" << std::endl;
//    for (auto i: v1) {
//        std::cout << i << " ";
//    }
//    return 0;
//}
