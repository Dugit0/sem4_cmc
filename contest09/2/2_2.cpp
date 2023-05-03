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
space_skip(int buf)
{
    while (std::isspace(buf)) {
        buf = std::getchar();
    }
    return buf;
}


int
value_skip(int buf)
{
    while (!(std::isspace(buf))) {
        buf = std::getchar();
    }
    return buf;
}


int
func(int buf)
{
    long long count_zero = 0;
    long long count_ones = 0;
    while (buf == '0') {
        count_zero++;
        buf = std::getchar();
    }
    while (buf == '1') {
        count_ones++;
        buf = std::getchar();
    }
    if (count_zero == 0 || count_ones == 0) {
        buf = value_skip(buf);
        return buf;
    }
//    std::cout << "deb : " << count_zero << " " << count_ones << std::endl;
//    std::cout << "deb : '" <<  (char) buf << "' (code = " << buf << ")" << std::endl;

    while (!std::isspace(buf)) {
        long long tmp_count_zero = 0;
        long long tmp_count_ones = 0;
        while (buf == '0') {
            tmp_count_zero++;
            buf = std::getchar();
        }
        while (buf == '1') {
            tmp_count_ones++;
            buf = std::getchar();
        }
        if (count_ones != tmp_count_ones || count_zero != tmp_count_zero) {
//            std::cout << "deb : " << tmp_count_zero << " " << tmp_count_ones << std::endl;
            std::cout << "0" << std::endl;
            buf = value_skip(buf);
            return buf;
        }
    }
    std::cout << "1" << std::endl;
    return buf;
}


int
main(void)
{
    int buf = std::getchar();
    buf = space_skip(buf);
    while (buf != EOF) {
        buf = func(buf);
        buf = space_skip(buf);
    }
//    std::cout << std::isspace('a') << std::endl;

    return 0;
}
