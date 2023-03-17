#include <iostream>
#include <vector>

//using std::cin, std::cout, std::endl;

void
process(const std::vector<unsigned long> &vec1, std::vector<unsigned long> &vec2, unsigned long step)
{
    auto fir_iter = vec1.begin();
    auto sec_iter = vec2.rbegin();
    while (sec_iter != vec2.rend() && fir_iter < vec1.end()) {
//        std::cout << *fir_iter << " " << *sec_iter << std::endl;
        *sec_iter += *fir_iter;
        sec_iter++;
        fir_iter += step;
    }
    return;
}


//int
//main(void)
//{
//    const std::vector<unsigned long> v1 = {1, 2, 3, 4};
//    std::vector<unsigned long> v2 = {1, 2, 3};
//    process(v1, v2, 2);
//    for (auto i: v2) {
//        std::cout << i << " ";
//    }
//    return 0;
//}

