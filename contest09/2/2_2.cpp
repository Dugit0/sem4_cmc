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
space_skip()
{
    int buf = std::getchar();
    while (std::isspace(buf)) {
        buf = std::getchar();
    }
    return buf;
}

int
func(int buf)
{
    int flag_repite = 0;
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
    std::cout << count_zero << " " << count_ones << std::endl;
    std::cout << buf << std::endl;

    while (!std::isspace(buf)) {
        flag_repite = 1;
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
            std::cout << tmp_count_zero << " " << tmp_count_ones << std::endl;
            std::cout << "0" << std::endl;
            while (!std::isspace(buf)) {
                buf = std::getchar();
            }
            return buf;
        }
        buf = std::getchar();
    }
    std::cout << "1" << std::endl;
    return buf;
}

int
main(void)
{
    int buf = space_skip();
    while (buf != EOF) {
        while (!std::isspace(buf)) {
            func(buf);
        }
        buf = space_skip();
    }
//    std::cout << std::isspace('a') << std::endl;

    return 0;
}
