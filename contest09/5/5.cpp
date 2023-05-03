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
is_contain_nterm(std::string str)
{
    for (auto i = str.begin(); i != str.end(); i++) {
        if (std::isupper(*i)) {
            return true;
        }
    }
    return false;
}


bool
is_only_one_nterm(std::string str)
{
    return str.size() == 1 && std::isupper(str[0]);
}


bool
is_gram(std::vector<std::pair<std::string, std::string>> rules)
{
    if (rules.size() == 0) {
        return false;
    }
    bool flag_S = false;
    for (auto i = rules.begin(); i != rules.end(); i++) {
        if (is_contain_nterm(i->first)) {
            if (i->first.size() == 1 && i->first[0] == 'S') {
                flag_S = true;
            }
        } else {
            return false;
        }
    }
    if (!flag_S) {
        return false;
    }
    return true;
}


bool
is_ks_gram(std::vector<std::pair<std::string, std::string>> rules)
{
    for (auto i = rules.begin(); i != rules.end(); i++) {
        if (!(is_only_one_nterm(i->first))) {
            return false;
        }
    }
    return true;
}

bool
is_not_short_gram(std::vector<std::pair<std::string, std::string>> rules)
{
    bool flag_null = false;
    for (auto i = rules.begin(); i != rules.end(); i++) {
        if (i->second.size() == 1 && i->second[0] == '_') {
            if (i->first[0] == 'S') {
                flag_null = true;
            } else {
                return false;
            }
        }
    }
    if (flag_null) {
        for (auto i = rules.begin(); i != rules.end(); i++) {
            for (auto j = i->second.begin(); j != i->second.end(); j++) {
                if (*j == 'S') {
                    return false;
                }
            }
        }
    }
    return true;
}


int
main(void)
{
    std::vector<std::pair<std::string, std::string>> rules = {};
    std::string left, right;
    while (std::cin >> left >> right) {
        std::pair<std::string, std::string> new_pair{ left, right };
        rules.push_back(new_pair);
    }
    if (!(is_gram(rules))) {
        std::cout << "-1" << std::endl;
    } else if (is_ks_gram(rules)) {
        if (is_not_short_gram(rules)) {
            std::cout << "23" << std::endl;
        } else {
            std::cout << "2" << std::endl;
        }
    } else {
        std::cout << "10" << std::endl;
    }
//    for (auto el : rules) {
//        std::cout << el.first << " " << el.second << std::endl;
//    }
    return 0;
}

