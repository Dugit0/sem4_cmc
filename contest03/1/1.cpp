#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>


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
            im_p = std::stod(base.substr(sep + 1, base.size() - 1));
        }
        double re() const
        {
            return re_p;
        }
        double im() const
        {
            return im_p;
        }
        double abs2() const
        {
            return re_p * re_p + im_p * im_p;
        }
        double abs() const
        {
            return std::sqrt(abs2());
        }
        std::string to_string() const
        {
            int max_size_buf = 1000;
            char buf[max_size_buf];
            std::snprintf(buf, max_size_buf, "(%.10g,%.10g)", re_p, im_p);
            return std::string(buf);
        }
        complex &operator += (const complex right)
        {
            re_p += right.re();
            im_p += right.im();
            return *this;
        }
        complex &operator -= (const complex right)
        {
            re_p -= right.re();
            im_p -= right.im();
            return *this;
        }
        complex &operator *= (const complex right)
        {
            double new_re_p = re_p * right.re() - im_p * right.im();
            double new_im_p = re_p * right.im() + im_p * right.re();
            re_p = new_re_p;
            im_p = new_im_p;
            return *this;
        }
        complex &operator /= (const complex right)
        {
            double new_re_p = (re_p * right.re() + im_p * right.im()) / right.abs2();
            double new_im_p = (right.re() * im_p - re_p * right.im()) / right.abs2();
            re_p = new_re_p;
            im_p = new_im_p;
            return *this;
        }
        complex operator + (const complex right) const
        {
            complex res(re_p, im_p);
            res += right;
            return res;
        }
        complex operator - (const complex right) const
        {
            complex res(re_p, im_p);
            res -= right;
            return res;
        }
        complex operator * (const complex right) const
        {
            complex res(re_p, im_p);
            res *= right;
            return res;
        }
        complex operator / (const complex right) const
        {
            complex res(re_p, im_p);
            res /= right;
            return res;
        }
        complex operator ~ () const
        {
            complex tmp(re_p, -im_p);
            return tmp;
        }
        complex operator - () const
        {
            complex tmp(-re_p, -im_p);
            return tmp;
        }
    };
}

int
main()
{
    numbers::complex z1;
    numbers::complex z2 = "(1,2)";
    numbers::complex A("(0.02,1.123)");
    A += A;
    A += A + A;
    A.operator+=(A);
    std::cout << A.re() << " " << A.im() << std::endl;
    return 0;
}