#include <iostream>
#include <cmath>
#include <iomanip>

int
main(void)
{
    
    using std::cin, std::cout, std::endl;
    
    double x_i;
    double sum_x = 0;
    double sum_x_2 = 0;
    int n = 0;
    while (cin >> x_i) {
        sum_x += x_i;
        sum_x_2 += x_i * x_i;
        n++;
    }
    double aver = sum_x / n;
    double sigm = sum_x_2 - 2 * aver * sum_x + n * aver * aver;
    sigm /= n;
    sigm = std::sqrt(sigm);
    cout << std::setprecision(10) << aver << endl;
    cout << std::setprecision(10) << sigm << endl;
    
    return 0;
}


