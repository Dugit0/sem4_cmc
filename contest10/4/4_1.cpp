#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <vector>
#include <map>
#include <functional>
#include <new>

bool
is_oper(char a)
{
    return a == '*' || a == '/' || a == '+' || a == '-' || a == '&' || a == '^' || a == '|';
}

int
get_prior(char a)
{
    if (a == '*' || a == '/') {
        return 1;
    } else if (a == '+' || a == '-') {
        return 2;
    } else if (a == '&') {
        return 3;
    } else if (a == '^') {
        return 4;
    } else if (a == '|') {
        return 5;
    } else {
        return -1;
    }
}

/*
 * E -> (E)
 * E -> E+E | E-E | ...
 * E -> a | b | c | ...
 */


size_t
to_polish(std::string str, size_t cur_pos, std::vector<char> &ans)
{
    while (cur_pos != str.size()) {
//        std::cout << "deb : size " << str.size() << std::endl;
//        std::cout << "deb : cur_pos " << cur_pos << std::endl;
        char cur_char = str[cur_pos];
        if (cur_char == '(') {
            cur_pos++;
            cur_pos = to_polish(str, cur_pos, ans);
//             assert str[cur_pos] == ')'
            cur_pos++;
        } else if (std::islower(cur_char)) {
            ans.push_back(cur_char);
            cur_pos++;
            return cur_pos;
        } else if (is_oper(cur_char)) {
            char buf_oper = cur_char;
            cur_pos++;
            cur_pos = to_polish(str, cur_pos, ans);
            ans.push_back(buf_oper);
        } else if (cur_char == ')') {
            break;
        }
    }
    return cur_pos;
}


int
main(void)
{
//    std::string str;
//    std::cin >> str;
    std::string str = "(a+b)/(c+d)";
//    std::string str = "a+b+c+d";
//    std::string str = "(a+b)/(c+d+e+f)";
    std::vector<char> ans = {};
    size_t cur_pos = 0;
    while (cur_pos != str.size()) {
        std::cout << "deb : size " << str.size() << std::endl;
        std::cout << "deb : cur_pos " << cur_pos << std::endl;
        cur_pos = to_polish(str, cur_pos, ans);
//        if (str[cur_pos] == ')') {
//            cur_pos++;
//        }
    }
    for (auto el: ans) {
        std::cout << el << " ";
    }
    std::cout << std::endl;
    return 0;
}

