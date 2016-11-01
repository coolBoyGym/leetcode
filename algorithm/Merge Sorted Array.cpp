#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// �鲢�����Ѿ����������
// nums1ӵ���㹻�Ŀռ� ֱ�ӴӺ���ǰ���й鲢
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int cur = m - 1;
        for(int i = 0; i < n; ++i){ // i�Ǽ������� ��ʾ�Ѿ������nums2�����ֵĸ���
            while(cur >= 0 && nums1[cur] > nums2[n-1-i])
                nums1[cur+n-i] = nums1[cur--];
            nums1[cur+n-i] = nums2[n-1-i];
        }
    }
};
