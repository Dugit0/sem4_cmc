#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
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

