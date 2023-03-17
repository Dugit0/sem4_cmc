#include <iostream>
#include <string>

class StringView
{
    std::string *_str;
    size_t _begin;
    size_t _end;
public:
    StringView(
            std::string &s,
            size_t begin = 0,
            size_t count = std::string::npos)
    {
        _str = &s;
        if (begin >= s.size()) {
            _str = nullptr;
            _begin = 0;
            _end = 0;
        } else {
            _begin = begin;
            if (begin + count <= s.size()) {
                _end = begin + count;
            } else {
                _end = s.size();
            }
        }
    }

    StringView(
            const StringView &sv,
            size_t begin = 0,
            size_t count = std::string::npos)
    {
        _str = sv._str;
        if (begin >= sv.size()) {
            _str = nullptr;
            _begin = 0;
            _end = 0;
        } else {
            _begin = begin;
            if (begin + count <= sv.size()) {
                _end = begin + count;
            } else {
                _end = sv.size();
            }
        }
    }

    size_t
    length() const
    {
        return _end - _begin;
    }

    size_t
    size() const
    {
        return length();
    }

    char &
    operator[](size_t ind)
    {
        return (*_str)[_begin + ind];
    }

    StringView &
    operator=(const StringView &right) = delete;

    auto
    operator<=>(const StringView &right) const
    {
        return *_str <=> *right._str;
    }

    std::string
    str(
            size_t begin = 0,
            size_t count = std::string::npos) const
    {
        if (begin >= size()) {
            return "";
        } else {
            if (begin + count <= size()) {
                return _str->substr(begin, count);
            } else {
                return _str->substr(begin, size());
            }
        }
    }

    char &
    begin()
    {
        return (*_str)[_begin];
    }

    char &
    end()
    {
        return (*_str)[_end];
    }
};


int
main(void)
{
    std::string test1 = "123456789";
    std::string &test1_link = test1;
    auto a = StringView(test1_link, 1, 6);
    a[2] = 'q';
    auto b = StringView(a, 2, 10);
    std::cout << a.size() << std::endl;
    std::cout << a.length() << std::endl;
    std::cout << a.str() << std::endl;
    std::cout << a.str(2, 4) << std::endl;
    std::cout << a.str(2, 1000) << std::endl;
    std::cout << b.str() << std::endl;
    std::cout << b.str(100, 200) << std::endl;
    std::cout << (a < b) << std::endl;
    for (auto i : b) {
        std::cout << i << std::endl;
    }

    return 0;
}


