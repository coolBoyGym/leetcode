#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 删除数组中的指定元素 原地置换
// 两个指针 一个从头开始扫描 发现目标元素时就进行置换 同时另一个指针减1
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0, j = nums.size() - 1;
        while(i <= j){
            while(i <= j && nums[i] != val) ++i;
            if(i <= j){
                nums[i] = nums[j];
                j--;
            }
        }

        return (j + 1);
    }
};
