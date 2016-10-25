#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 二分法 + 鸽巢原理 空间复杂度O(1) 时间复杂度O(nlogn)
// 注意判断条件与返回值是相互对应的
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int i, low = 1, high = n-1, middle = 0, cnt = 0;
        while(low <= high){
            middle = (low + high) / 2;
            cnt = 0;
            for(i = 0; i < n; ++i)
            {
                if(nums[i] <= middle) ++cnt;
            }
            if(cnt > middle) high = middle - 1;
            else low = middle + 1;
        }

        return low;
    }
};
