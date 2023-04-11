#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <vector>
#include <map>
#include <functional>
#include <new>


class Result
{
public:
    long long ans;
    Result(long long x) : ans(x) {}
};

void
func(long long a, long long b, long long k)
{
    try {
        if (k == 0) {
            throw Result(a + b);
        } else if (k > 0 && b == 1) {
            throw Result(a);
        } else if (k > 0 && b > 1) {
            long long tmp = 0;
            try {
                func(a, b - 1, k);
            } catch (Result res){
                tmp = res.ans;
            }
            try {
                func(a, tmp, k - 1);
            } catch (Result res){
                throw Result(res.ans);
            }
            return ;
        }
    } catch (Result ans) {
        throw ans;
    }
}

int
main(void)
{
    long long a, b, k;
    while (std::cin >> a >> b >> k) {
        try {
            func(a, b, k);
        } catch (Result res){
            std::cout << res.ans << std::endl;
        }
    }
    return 0;
}

