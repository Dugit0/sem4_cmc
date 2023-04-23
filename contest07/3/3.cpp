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
#include <memory>

//class Figure
//{
//public:
//    virtual double
//    get_square() const
//    {
//        return 0;
//    }
//
//    virtual ~Figure()
//    {
//
//    }
//};
//
//class Rectangle : public Figure
//{
//    double _x, _y;
//public:
//    Rectangle(double x = 0, double y = 0)
//    {
//        _x = x;
//        _y = y;
//    }
//
//    static Rectangle *
//    make(std::string s)
//    {
//        std::stringstream my_stream;
//        my_stream << s;
//        double x, y;
//        my_stream >> x;
//        my_stream >> y;
//        auto obj = new Rectangle(x, y);
//        return obj;
//    }
//
//    double
//    get_square() const override
//    {
//        return _x * _y;
//    }
//};
//
//class Square : public Figure
//{
//    double _x;
//public:
//    Square(double x = 0)
//    {
//        _x = x;
//    }
//
//    static Square *
//    make(std::string s)
//    {
//        std::stringstream my_stream;
//        my_stream << s;
//        double x;
//        my_stream >> x;
//        auto obj = new Square(x);
//        return obj;
//    }
//
//    double
//    get_square() const override
//    {
//        return _x * _x;
//    }
//};
//
//class Circle : public Figure
//{
//    double _r;
//public:
//    Circle(double r = 0)
//    {
//        _r = r;
//    }
//
//    static Circle *
//    make(std::string s)
//    {
//        auto obj = new Circle(std::stod(s));
//        return obj;
//    }
//
//    double
//    get_square() const override
//    {
//        return M_PI * _r * _r;
//    }
//};


class Factory
{
public:
    static Factory &
    factory_instance()
    {
        static Factory instance;
        return instance;
    }

    Factory()
    {}

    Factory(Factory const &) = delete;

    void
    operator=(Factory const &) = delete;

    std::unique_ptr<Figure>
    make_figure(std::string str)
    {
        std::map<std::string, std::function<std::unique_ptr<Figure>(std::string)>> oper = {
                { "R", [](std::string params) {
                    return std::unique_ptr<Figure>(Rectangle::make(params));
                }},
                { "S", [](std::string params) {
                    return std::unique_ptr<Figure>(Square::make(params));
                }},
                { "C", [](std::string params) {
                    return std::unique_ptr<Figure>(Circle::make(params));
                }}
        };
        std::istringstream stream(str);
        std::string type;
        stream >> type;
        std::string params;
        std::getline(stream, params);
        return oper[type](params);
    }
};

bool
my_cmp(const std::unique_ptr<Figure> &f, const std::unique_ptr<Figure> &s)
{
    return f->get_square() < s->get_square();
}


int
main(void)
{
    std::string buf;
    std::vector<std::unique_ptr<Figure>> vec = {};
    while (std::getline(std::cin, buf)) {
        vec.push_back(Factory::factory_instance().make_figure(buf));
    }
    std::stable_sort(vec.begin(), vec.end(), my_cmp);
    for (auto el = vec.begin(); el != vec.end(); el++) {
        std::cout << (*el)->to_string() << std::endl;
    }
    return 0;
}
