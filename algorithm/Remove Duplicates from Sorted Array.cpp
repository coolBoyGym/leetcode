#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// 移除数组中的重复元素 不使用额外空间
// 借助快慢索引 跳过重复元素 完成比较与置换
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;

        int slow = 0, fast = 1;
        while(fast < nums.size()){
            if(nums[slow] != nums[fast])
                nums[++slow] = nums[fast];
            ++fast;
        }

        return slow + 1;
    }
};
