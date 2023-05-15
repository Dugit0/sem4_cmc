#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <vector>
#include <map>
#include <functional>
#include <new>


size_t
my_len(std::string str)
{
    if (str == "_") {
        return 0;
    } else {
        return str.size();
    }
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


bool
is_right_gram(std::vector<std::pair<std::string, std::string>> rules)
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
is_left_gram(std::vector<std::pair<std::string, std::string>> rules)
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
is_reg_gram(std::vector<std::pair<std::string, std::string>> rules)
{
    return is_right_gram(rules) || is_left_gram(rules);
}


bool
is_only_auto_right_gram(std::vector<std::pair<std::string, std::string>> rules)
{
    for (auto i = rules.begin(); i != rules.end(); i++) {
        std::string right = i->second;
        if (my_len(right) == 0) {
            return false;
        } else if (my_len(right) == 1) {
            if (std::isupper(right[0])) {
                return false;
            }
        } else if (my_len(right) == 2) {
            if (std::isupper(right[0]) || !std::isupper(right[1])) {
                return false;
            }
        } else {
            return false;
        }
    }
    return true;
}

bool
is_auto_right_gram(std::vector<std::pair<std::string, std::string>> rules)
{
    bool flag_null = false;
    for (auto i = rules.begin(); i != rules.end(); i++) {
        std::string right = i->second;
        if (my_len(right) == 0) {
            if (i->first == "S") {
                flag_null = true;
            } else {
                return false;
            }
        }
    }
    if (flag_null) {
        std::vector<std::pair<std::string, std::string>> new_rules = {};
        for (auto i = rules.begin(); i != rules.end(); i++) {
            if (i->first != "S") {
                new_rules.push_back(*i);
            }
            for (auto j = i->second.begin(); j != i->second.end(); j++) {
                if (*j == 'S') {
                    return false;
                }
            }
        }
        return is_only_auto_right_gram(new_rules);
    } else {
        return is_only_auto_right_gram(rules);
    }
}




bool
is_only_auto_left_gram(std::vector<std::pair<std::string, std::string>> rules)
{
    for (auto i = rules.begin(); i != rules.end(); i++) {
        std::string right = i->second;
        if (my_len(right) == 0) {
            return false;
        } else if (my_len(right) == 1) {
            if (std::isupper(right[0])) {
                return false;
            }
        } else if (my_len(right) == 2) {
            if (!std::isupper(right[0]) || std::isupper(right[1])) {
                return false;
            }
        } else {
            return false;
        }
    }
    return true;
}

bool
is_auto_left_gram(std::vector<std::pair<std::string, std::string>> rules)
{
    bool flag_null = false;
    for (auto i = rules.begin(); i != rules.end(); i++) {
        std::string right = i->second;
        if (my_len(right) == 0) {
            if (i->first == "S") {
                flag_null = true;
            } else {
                return false;
            }
        }
    }
    if (flag_null) {
        std::vector<std::pair<std::string, std::string>> new_rules = {};
        for (auto i = rules.begin(); i != rules.end(); i++) {
            if (i->first != "S") {
                new_rules.push_back(*i);
            }
            for (auto j = i->second.begin(); j != i->second.end(); j++) {
                if (*j == 'S') {
                    return false;
                }
            }
        }
        return is_only_auto_left_gram(new_rules);
    } else {
        return is_only_auto_left_gram(rules);
    }
}



//bool
//is_auto_left_gram(std::vector<std::pair<std::string, std::string>> rules)
//{
//    bool flag_null = false;
//    for (auto i = rules.begin(); i != rules.end(); i++) {
//        std::string right = i->second;
//        if (my_len(right) == 0) {
//            if (i->first == "S") {
//                flag_null = true;
//            } else {
//                return false;
//            }
//        } else if (my_len(right) == 1) {
//            if (std::isupper(right[0])) {
//                return false;
//            }
//        } else if (my_len(right) == 2) {
//            if (!std::isupper(right[0]) || std::isupper(right[1])) {
//                return false;
//            }
//        } else {
//            return false;
//        }
//    }
//    if (flag_null) {
//        for (auto i = rules.begin(); i != rules.end(); i++) {
//            for (auto j = i->second.begin(); j != i->second.end(); j++) {
//                if (*j == 'S') {
//                    return false;
//                }
//            }
//        }
//    }
//    return true;
//}


bool
is_auto_gram(std::vector<std::pair<std::string, std::string>> rules)
{
    return is_auto_right_gram(rules) || is_auto_left_gram(rules);
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

    if (!is_not_short_gram(rules) && !is_reg_gram(rules)) {
        std::cout << "2" << std::endl;
    } else if (is_not_short_gram(rules) && !is_reg_gram(rules)) {
        std::cout << "21" << std::endl;
    } else if (is_left_gram(rules) && !is_auto_left_gram(rules)) {
        std::cout << "31" << std::endl;
    } else if (is_auto_left_gram(rules)) {
        std::cout << "311" << std::endl;
    } else if (is_right_gram(rules) && !is_auto_right_gram(rules)) {
        std::cout << "32" << std::endl;
    } else if (is_auto_right_gram(rules)) {
        std::cout << "321" << std::endl;
    }
    return 0;
}

