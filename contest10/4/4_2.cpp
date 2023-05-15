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

int
my_max(int a, int b, int c)
{
    int max = std::max(a, b);
    max = std::max(max, c);
    return max;
}

std::string
to_normal(std::vector<char> vec)
{
    std::string ans = "";
//    std::stack<std::string> stc = {};
    std::stack<std::pair<std::string, int>> stc = {};
    for (auto i = vec.begin(); i != vec.end(); i++) {
        if (std::islower(*i)) {
            std::string buf(1, *i);
            stc.push({ buf, 0 });
        } else {
            std::string s2 = stc.top().first;
            int p2 = stc.top().second;
            stc.pop();
            std::string s1 = stc.top().first;
            int p1 = stc.top().second;
            stc.pop();
            std::string buf(1, *i);
            int p3 = get_prior(*i);
            int prior = p3; // ???
            if (p1 > p3) {
                s1 = "(" + s1 + ")";
            }
            if (p2 >= p3) {
                s2 = "(" + s2 + ")";
            }
//            buf = "(" + s1 + buf + s2 + ")";
            buf = s1 + buf + s2;
            stc.push({ buf, prior });
        }
    }
    return stc.top().first;
}


int
main(void)
{
    std::string str;
    std::cin >> str;
//    std::string str = "(a+b)/(c+d)";
//    std::string str = "a+b*c";
//    std::string str = "(a+b)/(c+d+e+f)";
//    std::string str = "a+(b*c)";
//    std::vector<std::string> tests = {
//            "(a+b)/(c+d)",
//            "a+b*c",
//            "(a+b)/(c+d+e+f)",
//            "a+(b*c)",
//            "((a+b)+(c+d))",
//            "((a)+b)&c^d",
//            "(((a)&b^c|((d))))",
//            "a"
//    };
//    for (auto str : tests) {
    std::vector<char> pol = to_polish(str);
    std::string ans = to_normal(pol);
    std::cout << ans << std::endl;

//    }

    return 0;
}

