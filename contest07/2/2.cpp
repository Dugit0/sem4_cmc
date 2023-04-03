#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <vector>
#include <map>
#include <functional>
#include <new>

class Figure
{
public:
    virtual double
    get_square() const
    {
        return 0;
    }

    virtual ~Figure()
    {

    }
};

class Rectangle : Figure
{
    double _x, _y;
public:
    Rectangle(double x = 0, double y = 0)
    {
        _x = x;
        _y = y;
    }
    static Rectangle *
    make(std::string s)
    {
        std::stringstream my_stream;
        my_stream << s;
        double x, y;
        my_stream >> x;
        my_stream >> y;
        auto obj = new Rectangle(x, y);
        return obj;
    }
    double
    get_square() const override
    {
        return _x * _y;
    }
};

class Square : Figure
{
    double _x;
public:
    Square(double x = 0)
    {
        _x = x;
    }
    static Square *
    make(std::string s)
    {
        std::stringstream my_stream;
        my_stream << s;
        double x;
        my_stream >> x;
        auto obj = new Square(x);
        return obj;
    }
    double
    get_square() const override
    {
        return _x * _x;
    }
};

class Circle : Figure
{
    double _r;
public:
    Circle(double r = 0)
    {
        _r = r;
    }
    static Circle *
    make(std::string s)
    {
        auto obj = new Circle(std::stod(s));
        return obj;
    }
    double
    get_square() const override
    {
        return M_PI * _r * _r;
    }
};


//int
//main(void)
//{
//    Circle s;
//    auto n = s.make("10");
//    std::cout << n->get_square() << std::endl;
//    return 0;
//}

