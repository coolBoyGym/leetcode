#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

// 求两个无序整形数组的交集 保留重复元素
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        map<int, int> m;    // map中第二维初始化为0
        int n1 = nums1.size(), n2 = nums2.size();

        for(int i = 0; i < n1; ++i)
            m[nums1[i]]++;
        for(int i = 0; i < n2; i++)
        {
            if(m[nums2[i]] != 0){
                m[nums2[i]]--;
                res.push_back(nums2[i]);
            }
        }

        return res;
    }
};


// 先对两个数组分别排序 再用两个指针分别从头遍历
class Solution2 {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        int i = 0, j = 0;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                res.push_back(nums1[i]);
                ++i; ++j;
            } else if (nums1[i] > nums2[j]) {
                ++j;
            } else {
                ++i;
            }
        }
        return res;
    }
};
