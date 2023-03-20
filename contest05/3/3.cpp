#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>
#include <string>
#include <set>

class Date
{
public:
    unsigned int year = 0;
    unsigned int mounth = 0;
    unsigned int day = 0;

    Date()
    {
        year = 0;
        mounth = 0;
        day = 0;
    }

    Date(std::string str)
    {
        size_t f_ind = str.find('/');
        size_t s_ind = str.rfind('/');
//        std::cout << str.substr(0, f_ind) << std::endl;
        year = std::stoi(str.substr(0, f_ind));
//        std::cout << str.substr( f_ind, s_ind - f_ind) << std::endl;
        mounth = std::stoi(str.substr(f_ind + 1, s_ind - f_ind));
//        std::cout << str.substr(s_ind, str.size() - s_ind) << std::endl;
        day = std::stoi(str.substr(s_ind + 1, str.size() - s_ind));
    }

    std::string
    print() const
    {
        char buf[11] = {};
        snprintf(buf, 11, "%04u/%02u/%02u", year, mounth, day);
        std::string ans(buf);
        return ans;
    }

    auto
    operator<=>(const Date &right) const
    {
        return print() <=> right.print();
    }

    auto
    operator==(const Date &right) const
    {
        return print() == right.print();
    }
};


int
main(void)
{
    std::map<std::string, std::map<Date, int>> dict;
    std::set<Date> all_dates;
    std::string name;
    int mark;
    std::string date;
    while (std::cin >> name) {

        std::cin >> date;
        all_dates.insert(date);
//        std::cout << "date " << date << std::endl;
        std::cin >> mark;
        dict[name][date] = mark;
    }
    std::cout << ". ";
    for (auto i: all_dates) {
        std::cout << i.print() << " ";
    }
    std::cout << std::endl;
    for (auto user : dict) {
        std::cout << user.first << " ";
        for (auto cur_date : all_dates) {
            if (user.second.find(cur_date) == user.second.end()) {
                std::cout << ". ";
            } else {
                std::cout << user.second[cur_date] << " ";
            }
        }
        std::cout << std::endl;
    }
//    for (auto i : dict) {
//        std::cout << i.second << std::endl;
//    }
    return 0;
}

