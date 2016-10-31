#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// 还是借用了快慢两个索引 同时增加了一个计数变量
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;

        int slow = 0, fast = 1, count = 1;
        while(fast < nums.size()){
            if(nums[slow] != nums[fast]){
                nums[++slow] = nums[fast];
                count = 1;
            } else {
                ++count;
                if(count == 2)  nums[++slow] = nums[fast];
            }

            ++fast;
        }

        return slow + 1;
    }
};

/*
// 冒号用法和c++版本有关
class Solution2 {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (int n : nums)
            if (i < 2 || n > nums[i-2])
                nums[i++] = n;
        return i;
    }
};
*/
