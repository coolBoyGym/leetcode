#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 关键在于先找到最高的那根柱子 然后从两边分别往这个位置进行遍历
// 在遍历过程中 一旦发现有可以注水的地方就注水 最高的那根柱子保证了这些水不会流走
// 最重要的就是找到最大高度 这样就可以固定一边 另一边只要高度允许就可以注水
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n <= 2)
            return 0;

        int i, max = height[0], max_index = 0;
        for(i = 1; i < n; ++i)
            if(height[i] > max){
                max = height[i];
                max_index = i;
            }

        int water = 0, curr_height = 0; // water是当前的注水量 curr_height是当前可注水的最大高度
        for(i = 0; i < max_index; i++)
        {
            if(curr_height >= height[i])
                water += curr_height - height[i];    // 根据当前最大高度与该位置的差值进行注水
            else
                curr_height = height[i];     // 发现更大的高度 更新该值
        }

        curr_height = 0;    // 从另一个方向开始注水
        for(i = n-1; i > max_index; i--)
        {
            if(curr_height >= height[i])
                water += curr_height - height[i];
            else
                curr_height = height[i];
        }

        return water;   // 返回最终的注水量
    }
};
