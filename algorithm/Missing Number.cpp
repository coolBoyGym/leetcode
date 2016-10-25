#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

// �����������ԣ�����һ����������Լ���0�����0���Լ���
// �������ǰ�0-n�����һ�飬�ٶ��Ÿ����������һ�飬�������ȱʧ����
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for(int i = 0; i <= n; ++i)
            res = res ^ (i == n ? i : i ^ nums[i]);

        return res;
    }
};


// �ȶ�0~n��� �ٶ�������� ���߲�ֵ��Ϊȱʧ������
class Solution2 {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int res0 = n * (n + 1) / 2;
        // ������Ԫ����͵����ú��� ����ֵ�����ǵ���������������
        int res1 = accumulate(nums.begin(), nums.end(), 0);
        //for(int i = 0; i < n; ++i)
        //  res1 += nums[i];

        return res0 - res1;
    }
};
