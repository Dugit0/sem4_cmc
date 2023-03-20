#include <iostream>
#include <vector>
#include <map>
#include <algorithm>



int
main(void)
{
    std::map<std::string, double> dict;
    std::map<std::string, int> num_marks;
    std::string name;
    int mark;
    while (std::cin >> name) {
        std::cin >> mark;
        dict[name] += mark;
        num_marks[name] += 1;
    }
    for (auto i : dict) {
        std::cout << i.first << " " << i.second / num_marks[i.first] << std::endl;
    }
    return 0;
}

