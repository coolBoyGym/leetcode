#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

// 求两个无序整形数组的交集 去除重复元素
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        map<int, int> m;    // map中第二维初始化为0
        int n1 = nums1.size(), n2 = nums2.size();

        for(int i = 0; i < n1; ++i)
            m[nums1[i]]++;
        for(int i = 0; i < n2; i++)
        {
            if(m[nums2[i]] != 0){
                m[nums2[i]] = 0;    // 将m中的对应关系置为0 保证不出现重复元素
                res.push_back(nums2[i]);
            }
        }

        return res;
    }
};


// 利用集合的迭代器
class Solution2 {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int>s1,s2;
        int n1=nums1.size(),n2=nums2.size();
        for(int i=0;i<n1;i++) s1.insert(nums1[i]);
        for(int i=0;i<n2;i++) s2.insert(nums2[i]);
        vector<int>res;
        set<int>::iterator it1=s1.begin(),it2=s2.begin();
        while(it1!=s1.end()&&it2!=s2.end())
        {
            if(*it1==*it2)
            {
                res.push_back(*it1);
                it1++;
                it2++;
            }
            else if(*it1<*it2) it1++;
            else it2++;
        }
        return res;
    }
};


class Solution3 {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s(nums1.begin(), nums1.end()), res;
        for (int i = 0; i < nums2.size(); ++i) {
            if (s.count(nums2[i])) res.insert(nums2[i]);
        }
        return vector<int>(res.begin(), res.end());
    }
};

// 使用集合的交集操作
class Solution4 {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1(nums1.begin(), nums1.end()), s2(nums2.begin(), nums2.end()), res;
        set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(res, res.begin()));
        return vector<int>(res.begin(), res.end());
    }
};
