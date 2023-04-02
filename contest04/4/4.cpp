#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <vector>
#include <map>
#include <functional>
#include <new>


class Mean
{
    double _sum;
    unsigned int _count;
public:
    Mean(double sum = 0, unsigned int count = 0)
    {
        _sum = sum;
        _count = count;
    };

    void
    operator()(double n)
    {
        _sum += n;
        _count++;
    }

    double
    get_value() const
    {
        return _sum / _count;
    }
};

int
main(void)
{
    std::vector<double> vec{};
    double buf;
    while (std::cin >> buf) {
        vec.push_back(buf);
    }
    unsigned int n = vec.size();
    unsigned int drop1 = n / 10;
//    std::cout << drop1 << std::endl;
    auto begin = vec.begin() + drop1;
    auto end = vec.end() - drop1;
    std::sort(begin, end);
//    std::cout << end - begin << std::endl;
    unsigned int drop2 = (end - begin) / 10;
    begin += drop2;
    end -= drop2;

    Mean mean = std::for_each(begin, end, Mean());

//    for (auto el = begin; el < end; el++) {
//        std::cout << *el << " ";
//    }
    std::cout << std::fixed << std::setprecision(10) << mean.get_value() << std::endl;
    return 0;
}

