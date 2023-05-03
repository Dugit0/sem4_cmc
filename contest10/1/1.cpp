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


bool
is_left_gram(std::vector<std::pair<std::string, std::string>> rules)
{
    for (auto i = rules.begin(); i != rules.end(); i++) {
        std::string right = i->second;
        auto end = right.end();
        if (std::isupper(*right.rbegin())) {
            end--;
        }
        for (auto j = right.begin(); j != end; j++) {
            if (std::isupper(*j)) {
                return false;
            }
        }
    }
    return true;
}


bool
is_right_gram(std::vector<std::pair<std::string, std::string>> rules)
{
    for (auto i = rules.begin(); i != rules.end(); i++) {
        std::string right = i->second;
        auto begin = right.begin();
        if (std::isupper(*begin)) {
            begin++;
        }
        for (auto j = begin; j != right.end(); j++) {
            if (std::isupper(*j)) {
                return false;
            }
        }
    }
    return true;
}


bool
is_auto_left_gram(std::vector<std::pair<std::string, std::string>> rules)
{
    bool flag_null = false;
    for (auto i = rules.begin(); i != rules.end(); i++) {
        if (i->first.size() == 1 && i->first[0] == 'S' && i->second.size() == 1 && i->second[0] == '_') {
            flag_null = true;
            break;
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
    // Переписать!
//    for (auto i = rules.begin(); i != rules.end(); i++) {
//        std::string right = i->second;
//        if (flag_null) {
//            if (i->first.size() == 1 && i->first[0] == 'S') {
//                if (!(right.size() == 1 && (std::isupper(right[0]) || right[0] == '_'))) {
//                    return false;
//                }
//            }
//        } else {
//            if (!((right.size() == 1 && std::islower(right[0])) ||
//                  (right.size() == 2 && std::isupper(right[0]) && !std::isupper(right[1])))) {
//                return false;
//            }
//        }
//    }
    return true;
}


bool
is_auto_right_gram(std::vector<std::pair<std::string, std::string>> rules)
{
    for (auto i = rules.begin(); i != rules.end(); i++) {
        std::string right = i->second;
        if (!((right.size() == 1 && !std::isupper(right[0])) ||
              (right.size() == 2 && !std::isupper(right[0]) && std::isupper(right[1])))) {
            return false;
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


    return 0;
}

