#include <iostream>


class StringView
{
    std::string &_str;
    size_t _begin;
    size_t _end;
public:
    StringView(
            std::string &s,
            size_t begin = 0,
            size_t count = std::string::npos)
    {
        if (begin > s.size()) {
            
        }
    }

    StringView(
            const StringView &sv,
            size_t begin = 0,
            size_t count = std::string::npos)
    {

    }

    size_t
    length()
    {
    }

    size_t
    size()
    {
        return length();
    }

    char
    operator[](size_t ind)
    {

    }

    std::string
    str(
            size_t begin = 0,
            size_t count = std::string::npos) const
    {

    }
    auto
    begin()
    {

    }
    auto
    end()
    {

    }
};


int
main(void)
{

    return 0;
}


