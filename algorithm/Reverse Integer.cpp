#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <limits.h>
using namespace std;

// ��һ���������������
class Solution {
public:
    int reverse(int x) {
        long long res = 0;
        while(x) {
            res = res*10 + x%10;
            x /= 10;
        }

        return (res<INT_MIN || res>INT_MAX) ? 0 : res;
    }
};
