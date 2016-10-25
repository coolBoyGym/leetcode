#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 在两个已经排序好的数组中寻找第k小的数 复杂度log(m+n)
double findKth(vector<int>& nums1, int m, vector<int>& nums2, int n, int k)
{
    // 保证nums1数组的大小不大于nums2数组
    if(m > n)
        return findKth(nums2, n, nums1, m, k);
    if(m == 0)
        return nums2[k-1];
    if(k == 1)
        return min(nums1[0], nums2[0]);

    int pa = min(k / 2, m), pb = k - pa;
    if(nums1[pa-1] < nums2[pb-1])
    {
        vector<int> a(nums1.begin()+pa, nums1.end());
        return findKth(a, m - pa, nums2, n, k - pa);
    }
    else if(nums1[pa-1] > nums2[pb-1])
    {
        vector<int> b(nums2.begin()+pb, nums2.end());
        return findKth(nums1, m, b, n-pb, k-pb);
    }
    else
        return nums1[pa-1];
}

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int total = m + n;
        if(total % 2)
            return findKth(nums1, m, nums2, n, total / 2 + 1);
        else
            return (findKth(nums1, m, nums2, n, total / 2)
                    + findKth(nums1, m, nums2, n, total / 2 + 1)) / 2;
    }
};
