#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// �ҳ�������δ���ֵ���С��������
// ��ϣ�㷨 ����ʱ�� �����ڴ�
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        // ��һ��ɨ�� ��֤ÿһ�����ֵĲ�����n��������t���洢��t-1��λ����(��ĳ�����ֶ��ֻȡһ��)
        for(int i = 0; i < n; ++i){
            int val = nums[i];
            if(val > 0 && val <= n && nums[val-1] != val)
            {
                swap(nums[val-1], nums[i]);
                i--;
            }
        }

        // �ڶ���ɨ�� ��ǰ���� һ������ĳ��λ���ϵ�������ȷ ��Ϊδ���ֵ���������λ��
        for(int i = 0; i < n; ++i)
        {
            if(nums[i] != i+1)
                return i + 1;
        }

        // ��������n����ǡ����1~n ��ô����n+1
        return n + 1;
    }
};
