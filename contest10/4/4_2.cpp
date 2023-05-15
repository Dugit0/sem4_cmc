#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <vector>
#include <map>
#include <functional>
#include <stack>
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


std::vector<char>
to_polish(std::string str)
{
    str = str + "#";
    std::vector<char> ans = {};
    std::stack<char> buf = {};
    size_t cur_pos = 0;
    buf.push('#');
    while (true) {
        if (std::islower(str[cur_pos])) {
            ans.push_back(str[cur_pos]);
            cur_pos++;
        } else if (is_oper(str[cur_pos])) {
            if (buf.top() == '#' || buf.top() == '(') {
                buf.push(str[cur_pos]);
                cur_pos++;
            } else if (get_prior(str[cur_pos]) >= get_prior(buf.top())) {
                ans.push_back(buf.top());
                buf.pop();
            } else {
                buf.push(str[cur_pos]);
                cur_pos++;
            }
        } else if (str[cur_pos] == '(') {
            buf.push(str[cur_pos]);
            cur_pos++;
        } else if (str[cur_pos] == ')') {
            if (buf.top() == '(') {
                buf.pop();
                cur_pos++;
            } else {
                ans.push_back(buf.top());
                buf.pop();
            }
        } else if (str[cur_pos] == '#') {
            if (buf.top() != '#') {
                ans.push_back(buf.top());
                buf.pop();
            } else {
//                cur_pos++;
                break;
            }
        }
    }
    return ans;
}


std::string
to_normal(std::vector<char> vec)
{
    std::string ans = "";
    std::stack<std::string> stc = {};
    for (auto i = vec.begin(); i != vec.end(); i++) {
        if (std::islower(*i)) {
            std::string buf(1, *i);
            stc.push(buf);
        } else {
            std::string s2 = stc.top();
            stc.pop();
            std::string s1 = stc.top();
            stc.pop();
            std::string buf(1, *i);
//            buf = "(" + s1 + buf + s2 + ")";
            buf = s1 + buf + s2;
            stc.push(buf);
        }
    }
    return stc.top();
}




int
main(void)
{
//    std::string str;
//    std::cin >> str;
//    std::string str = "(a+b)/(c+d)";
//    std::string str = "a+b*c";
    std::string str = "(a+b)/(c+d+e+f)";
    std::vector<char> pol = to_polish(str);
    for (auto el: pol) {
        std::cout << el << " ";
    }
    std::cout << std::endl;
    std::string ans = to_normal(pol);
    std::cout << ans << std::endl;

    return 0;
}

