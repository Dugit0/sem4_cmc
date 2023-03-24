#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <vector>
#include <map>
#include <functional>
#include <new>
#include "cmc_complex.h"
#include "cmc_complex_stack.h"
#include "cmc_complex_eval.h"


int
main(int argc, char *argv[])
{
    numbers::complex c(argv[1]);
    double r = std::stod(argv[2]);
    int n = std::stoi(argv[3]);
    std::vector<std::string> expression;
    for (int i = 4; i < argc; i++) {
        expression.push_back(argv[i]);
    }
//    for (auto i : expression) {
//        std::cout << i << std::endl;
//    }

    numbers::complex ans(0, 0);
    double d_phi = 2 * M_PI / n;
    for (int i = 0; i < n; i++) {
        double phi_ksi = (i + 0.5) * d_phi;
        numbers::complex dot(c.re() + r * cos(phi_ksi), c.im() + r * sin(phi_ksi));
        double phi_i0 = i * d_phi;
        double phi_i1 = (i + 1) * d_phi;
        numbers::complex dl(r * (cos(phi_i1) - cos(phi_i0)), r * (sin(phi_i1) - sin(phi_i0)));
        ans += numbers::eval(expression, dot) * dl;
    }
    std::cout << ans.to_string() << std::endl;
    return 0;
}

