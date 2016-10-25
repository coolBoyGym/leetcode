#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

// 一个n元数组 每个数代表一个孩子的权重 现在要给他们分糖 要求是：
// 1. 每个孩子至少拿到一颗糖
// 2. 某个孩子权重比他的邻居大 则他要拿到更多糖
// 如何在这两个要求下分发最少的糖果

// 两遍扫描 第一遍从右往左 第二遍从左往右 每次比较这一方向上相邻点权重大小 并进行更新
// 经过实验发现 两遍扫描的先后顺序不重要
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int * candies = new int[n];
        for(int i = 0; i < n; ++i)
            candies[i] = 1;
        for(int i = n-1; i > 0; i--)
        {
            if(ratings[i-1] > ratings[i])
                candies[i-1] = candies[i] + 1;
        }
        for(int i = 0; i < n-1; ++i)
        {
            if(ratings[i+1] > ratings[i]){
                int tmp = candies[i] + 1;
                if(candies[i+1] < tmp)
                    candies[i+1] = tmp;
            }
        }

        int count = 0;
        for(int i = 0; i < n; ++i)
            count += candies[i];

        delete [] candies;
        return count;
    }

};
