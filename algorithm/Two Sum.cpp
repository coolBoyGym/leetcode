#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

// 在数组中找到两个数 使得它们的和为一个给定值
// map查找某一个元素只要常数时间
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        unsigned int i;
        vector<int> results;
        map<int, int> hmap;

        // 使用map时一个关键点是map如何初始化
        for(i=0; i<numbers.size(); i++){
            if(!hmap.count(numbers[i])){
                hmap.insert(pair<int, int>(numbers[i], i));
            }
            if(hmap.count(target-numbers[i])){
                unsigned int n = hmap[target-numbers[i]];
                if(n < i){
                    results.push_back(n);
                    results.push_back(i);
                    return results;
                }
            }
        }

        return results;
    }
};

/*
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res(0, 0);
        map<long long int, int> m;
        long long int tmp = 0;
        for(unsigned int i = 0; i < nums.size(); ++i)
        {
            tmp = target - nums[i];
            if(m.find(tmp) == m.end())
                m[nums[i]] = i;
            else
            {
                res[0] = i;
                res[1] = m[tmp];
                return res;
            }
        }
        return res;
    }
};
*/
