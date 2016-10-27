#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ɾ�������е�ָ��Ԫ�� ԭ���û�
// ����ָ�� һ����ͷ��ʼɨ�� ����Ŀ��Ԫ��ʱ�ͽ����û� ͬʱ��һ��ָ���1
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0, j = nums.size() - 1;
        while(i <= j){
            while(i <= j && nums[i] != val) ++i;
            if(i <= j){
                nums[i] = nums[j];
                j--;
            }
        }

        return (j + 1);
    }
};
