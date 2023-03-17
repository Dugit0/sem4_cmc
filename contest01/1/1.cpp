#include <iostream>


class Sum
{
public:
    int a;
    int b;
    Sum(int f1, int f2)
    {
        a = f1;
        b = f2;
    }
    Sum(Sum f1, int f2)
    {
        a = f1.get();
        b = f2;
    }
    int get(void) const
    {
        return a + b;
    }
};

int
main(void)
{
    using std::cin;
    using std::cout;
    using std::endl;
    int a = 10;
    int b = 24;
    int c = 30;
    /* std::cout << a << std::endl; */
    cout << Sum(a, b).get() << endl;
    cout << Sum(Sum(a, b), c).get() << endl;
    
    
    return 0;
}


