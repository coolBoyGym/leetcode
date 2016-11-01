#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// 归并两个已经排序的数组
// nums1拥有足够的空间 直接从后往前进行归并
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int cur = m - 1;
        for(int i = 0; i < n; ++i){ // i是计数变量 表示已经处理的nums2中数字的个数
            while(cur >= 0 && nums1[cur] > nums2[n-1-i])
                nums1[cur+n-i] = nums1[cur--];
            nums1[cur+n-i] = nums2[n-1-i];
        }
    }
};
