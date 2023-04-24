#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <vector>
#include <map>
#include <functional>
#include <new>
#include <sstream>

bool
is_operator(char s)
{
    return (s == '+' || s == '-' || s == '*' || s == '/');
}

std::pair<std::string, ssize_t>
parce(std::string str, ssize_t pos)
{
//    ssize_t len = str.size();
    if (!is_operator(str[pos])) {
//        std::cout << "deb : non-op " << str[pos] << std::endl;
//        std::cout << "deb : " << std::endl;
        std::string s(1, str[pos]);
        return {s, pos - 1};
    } else {
        // (is_operator(str[pos]))
//        std::cout << "deb : op " << str[pos] << std::endl;
        auto buf1 = parce(str, pos - 1);
        auto str1 = buf1.first;
//        std::cout << "deb : op str1 " << str1 << std::endl;
        auto new_pos = buf1.second;
        auto buf2 = parce(str, new_pos);
//        std::cout << "deb : op str2 " << buf2.first << std::endl;
        std::string op(1, str[pos]);
        std::string res = "(" + buf2.first + op + str1 + ")";
//        std::stringstream ss;
//        ss << "(" << str1 << str[pos] << buf.first << ")" << std::endl;
//        std::string res;
//        std::getline(ss, res);
//        std::cout << "deb : " << res << std::endl;
        return {res, buf2.second};
    }

}





int
main(void)
{
    std::string buf;
    std::cin >> buf;
//    std::string buf = "abc++";
    std::cout << parce(buf, buf.size() - 1).first << std::endl;
    return 0;
}

