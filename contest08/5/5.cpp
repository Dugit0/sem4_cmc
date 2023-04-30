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
#include <chrono>


int
main()
{
    std::chrono::year_month_day prev, buf;
    std::string date;
    int y, m, d;
    if (!(std::cin >> date)) {
        return 0;
    }
    std::replace(date.begin(), date.end(), '-', ' ');
    std::stringstream ss1(date);
    ss1 >> y >> m >> d;
    prev = std::chrono::year{y}/m/d;
    long long ans = 0;
//    std::chrono::duration<long long, std::ratio<86400, 1>> ans{};
    while (std::cin >> date) {
        std::replace(date.begin(), date.end(), '-', ' ');
        std::stringstream ss2(date);
        ss2 >> y >> m >> d;
        buf = std::chrono::year{y}/m/d;
        auto delt = std::chrono::sys_days{prev} - std::chrono::sys_days{buf};
        ans += std::abs(delt.count());
        prev = buf;
    }
    std::cout << ans << std::endl;
}

