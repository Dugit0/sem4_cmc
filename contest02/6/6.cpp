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
            _begin = sv._begin + begin;
            if (count <= sv.size()) {
                _end = _begin + count;
            } else {
                _end = sv._end;
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

    const char &
    at(size_t pos) const
    {
        if (pos < size()) {
            return (*_str)[_begin + pos];
        } else {
            throw std::out_of_range("out_of_range");
        }
    }

    char &
    at(size_t pos)
    {
        if (pos < size()) {
            return (*_str)[_begin + pos];
        } else {
            throw std::out_of_range("out_of_range");
        }
    }

    char
    operator[](size_t pos) const
    {
        return at(pos);
    }

    char &
    operator[](size_t pos)
    {
        return at(pos);
    }

    StringView &
    operator=(const StringView &right) = delete;

    auto
    operator<=>(const StringView &right) const
    {
        return str() <=> right.str();
    }

    auto
    operator==(const StringView &right) const
    {
        return str() == right.str();
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
//                std::cout << "1 : " << _str->substr(_begin + begin, count) << std::endl;
                return _str->substr(_begin + begin, count);
            } else {
//                std::cout << "2 : " << _str->substr(_begin + begin, size() - _begin - begin) << std::endl;
                return _str->substr(_begin + begin, size() - begin);
            }
        }
    }

    using iterator = std::string::iterator;
    using const_iterator = std::string::const_iterator;
    using reverse_iterator = std::string::reverse_iterator;
    using const_reverse_iterator = std::string::const_reverse_iterator;

    iterator
    begin()
    {
        return _str->begin() + _begin;
    }

    iterator
    end()
    {
        return _str->begin() + _end;
    }

    const_iterator
    cbegin()
    {
        return _str->cbegin() + _begin;
    }

    const_iterator
    cend()
    {
        return _str->cbegin() + _end;
    }

    reverse_iterator
    rbegin()
    {
        return _str->rbegin() + (_str->size() - _end);
    }

    reverse_iterator
    rend()
    {
        return _str->rbegin() + (_str->size() - _end + size());
    }

    const_reverse_iterator
    crbegin()
    {
        return _str->crbegin() + (_str->size() - _end);
    }

    const_reverse_iterator
    crend()
    {
        return _str->crbegin() + (_str->size() - _end + size());
    }

};


//void
//func_test_7(const StringView &sv)
//{
//    std::cout << sv[0];
//}
//
//void
//func_test_8(const StringView &sv)
//{
//    std::cout << sv.at(1);
//}
//
//int
//main(void)
//{
//    std::string test1 = "123456789";
//    std::string &test1_link = test1;
//    const std::string &test2_link = test1;
//    auto a = StringView(test1_link, 1, 6);
//    a[2] = 'q';
//    auto b = StringView(a, 3, 10);
////    std::cout << a.size() << std::endl;
////    std::cout << a.length() << std::endl;
////    std::cout << a.str() << std::endl;
////    std::cout << a.str(2, 4) << std::endl;
////    std::cout << a.str(2, 1000) << std::endl;
////    std::cout << b.str() << std::endl;
////    std::cout << b.str(100, 200) << std::endl;
//    std::cout << (a < b) << std::endl;
//    std::cout << (a == b) << std::endl;
////    std::cout << b.begin() << std::endl;
//    for (auto i: b) {
//        std::cout << i << std::endl;
//    }
//
////    StringView c(test2_link);
////    std::cout << c.str() << std::endl;
//
//    return 0;
//}


