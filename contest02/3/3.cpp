class C 
{
public:
    double a;
    C() = default;
    C(int c1)
    {
        a = c1;
    }
    C(C c1, int c2)
    {
        a = c1.a + c2;
    }
    C(C c1, C c2)
    {
        a = c1.a + c2.a;
    }


    /* friend C operator + (C c1) */
    /* { */
    /*     return C(0); */
    /* } */
    friend C operator + (int c1, C c2)
    {
        return C(0);
    }
    int operator ~ ()
    {
        return 0;
    }

    C operator * (C c1)
    {
        return C(0);
    }

    C& operator++ ()
    {
        return *this;
    }

    C operator &()
    {
        return *this;
    }

};


C func1(const C &v1, int v2)
{
    /* return C(v1 + v2, ~v1); */
    return C(v2 + v1, ~v1);
}

void func2(const C *p1, double p2)
{
    C v1 = p2;
    C v2[2][2];
    C v3 = func1(func1(func1(&p1[3], p2), ~p1[2]), ++v1 * v2[1]);
}    
  
