#include <iostream>
#include <string>

using std::string;

class BinaryNumber
{
    string _s;
public:
    BinaryNumber(const string &s)
    {
       _s = s;
    }
    operator string () const
    {
        return _s;
    }
    const BinaryNumber &operator++()
    {
        size_t start_ind = _s.rfind('0');
        if (start_ind == std::string::npos) {
            _s = "1" + string(_s.size(), '0');
        } else {
            for (size_t i = start_ind + 1; i < _s.size(); i++) {
                _s[i] = '0';
            }
            _s[start_ind] = '1';
        }
        return *this;
    }
};



//int
//main(void)
//{
//    string b = "10010101111000000";
////    string &s = b;
//    const string &ss = b;
//
//    BinaryNumber a(ss);
//    ++a;
////    std::cout << "meow" << std::endl;
//    string c = a;
//    std::cout << c << std::endl;
//    return 0;
//}


