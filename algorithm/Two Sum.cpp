#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

// ���������ҵ������� ʹ�����ǵĺ�Ϊһ������ֵ
// map����ĳһ��Ԫ��ֻҪ����ʱ��
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        unsigned int i;
        vector<int> results;
        map<int, int> hmap;

        // ʹ��mapʱһ���ؼ�����map��γ�ʼ��
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
