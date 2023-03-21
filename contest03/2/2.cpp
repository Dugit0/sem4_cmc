#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <new>

namespace numbers
{
// COMMENT COMPLEX BEFORE SEND (vj135)
//    class complex
//    {
//        double re_p, im_p;
//    public:
//        complex(double re_base = 0, double im_base = 0)
//        {
//            re_p = re_base;
//            im_p = im_base;
//        }
//
//        explicit complex(std::string base)
//        {
//            size_t sep = base.find(",");
//            re_p = std::stod(base.substr(1, sep));
//            im_p = std::stod(base.substr(sep + 1, (base.size() - 1) - (sep + 1)));
//        }
//
//        double
//        re() const
//        {
//            return re_p;
//        }
//
//        double
//        im() const
//        {
//            return im_p;
//        }
//
//        double
//        abs2() const
//        {
//            return re_p * re_p + im_p * im_p;
//        }
//
//        double
//        abs() const
//        {
//            return std::sqrt(abs2());
//        }
//
//        std::string
//        to_string() const
//        {
//            int max_size_buf = 1000;
//            char buf[max_size_buf];
//            std::snprintf(buf, max_size_buf, "(%.10g,%.10g)", re_p, im_p);
//            return std::string(buf);
//        }
//
//        complex &
//        operator+=(const complex right)
//        {
//            re_p += right.re();
//            im_p += right.im();
//            return *this;
//        }
//
//        complex &
//        operator-=(const complex right)
//        {
//            re_p -= right.re();
//            im_p -= right.im();
//            return *this;
//        }
//
//        complex &
//        operator*=(const complex right)
//        {
//            double new_re_p = re_p * right.re() - im_p * right.im();
//            double new_im_p = re_p * right.im() + im_p * right.re();
//            re_p = new_re_p;
//            im_p = new_im_p;
//            return *this;
//        }
//
//        complex &
//        operator/=(const complex right)
//        {
//            double new_re_p = (re_p * right.re() + im_p * right.im()) / right.abs2();
//            double new_im_p = (right.re() * im_p - re_p * right.im()) / right.abs2();
//            re_p = new_re_p;
//            im_p = new_im_p;
//            return *this;
//        }
//
//        friend complex
//        operator+(const complex left, const complex right)
//        {
//            complex res("(0,0)");
//            res += left;
//            res += right;
//            return res;
//        }
//
//        friend complex
//        operator-(const complex left, const complex right)
//        {
//            complex res("(0,0)");
//            res += left;
//            res -= right;
//            return res;
//        }
//
//        friend complex
//        operator*(const complex left, const complex right)
//        {
//            complex res("(0,0)");
//            res += left;
//            res *= right;
//            return res;
//        }
//
//        friend complex
//        operator/(const complex left, const complex right)
//        {
//            complex res("(0,0)");
//            res += left;
//            res /= right;
//            return res;
//        }
//
//        complex
//        operator~() const
//        {
//            complex tmp(re_p, -im_p);
//            return tmp;
//        }
//
//        complex
//        operator-() const
//        {
//            complex tmp(-re_p, -im_p);
//            return tmp;
//        }
//    };
// COMMENT COMPLEX BEFORE SEND

    class complex_stack
    {
        complex *_data;
        size_t _size;
    public:
        complex_stack()
        {
            _data = nullptr;
            _size = 0;
        }

        complex_stack(size_t size)
        {
            _data = new complex[size];
            _size = size;
        }

        complex_stack(const complex_stack &other)
        {
            _data = new complex[other.size()];
            _size = other.size();
            for (size_t i = 0; i < other.size(); i++) {
                _data[i] = other[i];
            }
        }

        complex_stack(complex_stack &&other) noexcept
        {
            _data = other._data;
            _size = other._size;
            other._data = nullptr;
            other._size = 0;
        }

        ~complex_stack()
        {
            delete[] _data;
        }

        size_t
        size() const
        {
            return _size;
        }

        complex
        operator[](size_t ind) const
        {
            return _data[ind];
        }

        complex_stack &
        operator=(const complex_stack &other)
        {
            if (this != &other) {
                delete[] _data;
                _data = new complex[other.size()];
                _size = other.size();
                for (size_t i = 0; i < other.size(); i++) {
                    _data[i] = other[i];
                }
            }
            return *this;
        }

        complex_stack
        operator<<(complex right) const
        {
            complex_stack ret(this->size() + 1);
            for (size_t i = 0; i < this->size(); i++) {
                ret._data[i] = this->_data[i];
            }
            ret._data[this->size()] = right;
            return ret;
        }

        complex
        operator+() const
        {
            return _data[_size - 1];
        }

        complex_stack
        operator~() const
        {
            complex_stack ret(this->size() - 1);
            for (size_t i = 0; i < this->size() - 1; i++) {
                ret._data[i] = this->_data[i];
            }
            return ret;
        }
    };
}

//int
//main()
//{
//    numbers::complex_stack s1(0);
//    numbers::complex_stack s2 = s1 << numbers::complex(1, 2) << numbers::complex(2, 2);
//
//    std::cout << s1.size() << std::endl;
//    std::cout << s2.size() << std::endl;
//    std::cout << (+s2).to_string() << std::endl;
//    std::cout << s2[0].to_string() << s2[1].to_string() << std::endl;
//    return 0;
//}
