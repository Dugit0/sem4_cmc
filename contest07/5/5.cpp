#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <vector>
#include <map>
#include <functional>
#include <new>
#include <cassert>

// Solution based on
// https://stackoverflow.com/questions/351845/finding-the-type-of-an-object-in-c


class Figure
{
public:
    virtual bool
    equals(const Figure *fig) const
    {
        return false;
    }

    virtual ~Figure()
    {

    }
};


class Rectangle : public Figure
{
public:
    int d1, d2;

    Rectangle(int a, int b)
    {
        d1 = a;
        d2 = b;
    }

    bool
    equals(const Figure *fig) const override
    {
        auto res = dynamic_cast<const Rectangle *>(fig);
        if (res) {
//            std::cout << "res not null" << std::endl;
            return (d1 == res->d1 && d2 == res->d2);
        } else {
//            std::cout << "res null" << std::endl;
            return false;
        }
    }
};


class Triangle : public Figure
{
public:
    int d1, d2, d3;

    Triangle(int a, int b, int c)
    {
        d1 = a;
        d2 = b;
        d3 = c;
    }

    bool
    equals(const Figure *fig) const override
    {
        auto res = dynamic_cast<const Triangle *>(fig);
        if (res) {
            return (d1 == res->d1 && d2 == res->d2 && d3 == res->d3);
        } else {
            return false;
        }
    }
};

//int
//main(void)
//{
//    Rectangle r1(10, 5), r2(10, 2), r3(10, 5), r4(5, 10);
//    Triangle t1(1, 2, 3);
//    Figure *f = &r1;
//
//    assert(!f->equals(&r2));
//    assert(f->equals(&r3));
//    assert(!f->equals(&r4));
//    assert(!f->equals(&t1));
//    assert(!f->equals(nullptr));
//    return 0;
//}

