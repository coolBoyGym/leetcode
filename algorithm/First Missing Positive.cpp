#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 找出数组中未出现的最小的正整数
// 哈希算法 线性时间 常量内存
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        // 第一遍扫描 保证每一个出现的不大于n的正整数t都存储在t-1的位置上(若某数出现多次只取一个)
        for(int i = 0; i < n; ++i){
            int val = nums[i];
            if(val > 0 && val <= n && nums[val-1] != val)
            {
                swap(nums[val-1], nums[i]);
                i--;
            }
        }

        // 第二遍扫描 从前往后 一旦发现某个位置上的数不正确 即为未出现的正整数的位置
        for(int i = 0; i < n; ++i)
        {
            if(nums[i] != i+1)
                return i + 1;
        }

        // 如果数组的n个数恰好是1~n 那么返回n+1
        return n + 1;
    }
};
