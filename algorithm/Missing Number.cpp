#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

// 根据异或的特性，对于一个数，异或自己是0，异或0是自己，
// 所以我们把0-n都异或一遍，再对着给定数组异或一遍，结果就是缺失的数
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for(int i = 0; i <= n; ++i)
            res = res ^ (i == n ? i : i ^ nums[i]);

        return res;
    }
};


// 先对0~n求和 再对数组求和 二者差值即为缺失的数字
class Solution2 {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int res0 = n * (n + 1) / 2;
        // 对向量元素求和的内置函数 返回值类型是第三个参数的类型
        int res1 = accumulate(nums.begin(), nums.end(), 0);
        //for(int i = 0; i < n; ++i)
        //  res1 += nums[i];

        return res0 - res1;
    }
};
