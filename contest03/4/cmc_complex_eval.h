//
// Created by dmitry on 3/22/23.
//

#ifndef CODE_CMC_COMPLEX_EVAL_H
#define CODE_CMC_COMPLEX_EVAL_H
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

namespace numbers
{
    complex
    eval(const std::vector <std::string> &args, const complex &z)
    {
        complex_stack stack;
        std::map <std::string, std::function<void(complex_stack & )>> operations{
                { "+", [](complex_stack &stack) { stack = (~~stack) << ((+~stack) + (+stack)); }},
                { "-", [](complex_stack &stack) { stack = (~~stack) << ((+~stack) - (+stack)); }},
                { "*", [](complex_stack &stack) { stack = (~~stack) << ((+~stack) * (+stack)); }},
                { "/", [](complex_stack &stack) { stack = (~~stack) << ((+~stack) / (+stack)); }},
                { "!", [](complex_stack &stack) { stack = stack << (+stack); }},
                { ";", [](complex_stack &stack) { stack = ~stack; }},
                { "~", [](complex_stack &stack) { stack = (~stack) << (~+stack); }},
                { "#", [](complex_stack &stack) { stack = (~stack) << (- +stack); }},
        };
        for (auto elem: args) {
//            std::cout << "elem : " << elem << std::endl;
            if (elem.size() == 1) {
//                std::cout << "elem size 1" << std::endl;
                if (std::isalpha(elem[0])) {
//                    std::cout << "elem alpha" << std::endl;
                    stack = stack << z;
                } else {
                    operations[elem](stack);
                }
            } else {
                stack = stack << complex(elem);
            }
        }
        return +stack;
    }
}
#endif //CODE_CMC_COMPLEX_EVAL_H
