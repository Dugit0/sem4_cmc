#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class A
{
public:
    int a;
    int flag_dest;
    A()
    {
        cin >> a;
        flag_dest = 0;
    }
    A(A const &f1)
    {
        cin >> a;
        a += f1.a;
        flag_dest = 1;
    }
    ~A()
    {
        if (this->flag_dest) {
            cout << a << endl;
        }
    }
};

/* int */
/* main(void) */
/* { */
/*     /1* int a = 10; *1/ */
/*     /1* int b = 24; *1/ */
/*     /1* int c = 30; *1/ */
/*     /1* std::cout << a << std::endl; *1/ */
/*     A a, b(a); */
    
/*     return 0; */
/* } */


