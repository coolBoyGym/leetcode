#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

// 求x的n次幂
// 借用递归思想:
//      若n为偶数 x^n = x^n/2 * x^n/2
//      若n为奇数 x^n = x * x^n/2 * x^n/2
class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0)
            return 1;
        else if(n < 0){
            if(n == INT_MIN)    // 样例中有一个n值为INT_MIN 直接取反会溢出
                return 1.0 / (myPow(x, INT_MAX) * x);
            else
                return 1.0 / myPow(x, -n);
        }

        double res = 1;
        while(n > 0){
            if(n % 2 == 1)
                res *= x;
            n /= 2;
            x *= x;
        }

        return res;
    }
};
