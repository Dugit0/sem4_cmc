//
// Created by dmitry on 3/22/23.
//

#ifndef CODE_CMC_COMPLEX_H
#define CODE_CMC_COMPLEX_H

#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <vector>
#include <map>
#include <functional>
#include <new>

namespace numbers
{
    class complex
    {
        double re_p, im_p;
    public:
        complex(double re_base = 0, double im_base = 0)
        {
            re_p = re_base;
            im_p = im_base;
        }

        explicit complex(std::string base)
        {
            size_t sep = base.find(",");
            re_p = std::stod(base.substr(1, sep));
            im_p = std::stod(base.substr(sep + 1, (base.size() - 1) - (sep + 1)));
        }

        double
        re() const
        {
            return re_p;
        }

        double
        im() const
        {
            return im_p;
        }

        double
        abs2() const
        {
            return re_p * re_p + im_p * im_p;
        }

        double
        abs() const
        {
            return std::sqrt(abs2());
        }

        std::string
        to_string() const
        {
            int max_size_buf = 1000;
            char buf[max_size_buf];
            std::snprintf(buf, max_size_buf, "(%.10g,%.10g)", re_p, im_p);
            return std::string(buf);
        }

        complex &
        operator+=(const complex right)
        {
            re_p += right.re();
            im_p += right.im();
            return *this;
        }

        complex &
        operator-=(const complex right)
        {
            re_p -= right.re();
            im_p -= right.im();
            return *this;
        }

        complex &
        operator*=(const complex right)
        {
            double new_re_p = re_p * right.re() - im_p * right.im();
            double new_im_p = re_p * right.im() + im_p * right.re();
            re_p = new_re_p;
            im_p = new_im_p;
            return *this;
        }

        complex &
        operator/=(const complex right)
        {
            double new_re_p = (re_p * right.re() + im_p * right.im()) / right.abs2();
            double new_im_p = (right.re() * im_p - re_p * right.im()) / right.abs2();
            re_p = new_re_p;
            im_p = new_im_p;
            return *this;
        }

        friend complex
        operator+(const complex left, const complex right)
        {
            complex res("(0,0)");
            res += left;
            res += right;
            return res;
        }

        friend complex
        operator-(const complex left, const complex right)
        {
            complex res("(0,0)");
            res += left;
            res -= right;
            return res;
        }

        friend complex
        operator*(const complex left, const complex right)
        {
            complex res("(0,0)");
            res += left;
            res *= right;
            return res;
        }

        friend complex
        operator/(const complex left, const complex right)
        {
            complex res("(0,0)");
            res += left;
            res /= right;
            return res;
        }

        complex
        operator~() const
        {
            complex tmp(re_p, -im_p);
            return tmp;
        }

        complex
        operator-() const
        {
            complex tmp(-re_p, -im_p);
            return tmp;
        }
    };
}



#endif //CODE_CMC_COMPLEX_H
