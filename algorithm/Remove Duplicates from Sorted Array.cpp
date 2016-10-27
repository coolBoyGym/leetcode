#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// �Ƴ������е��ظ�Ԫ�� ��ʹ�ö���ռ�
// ������������ �����ظ�Ԫ�� ��ɱȽ����û�
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;

        int slow = 0, fast = 1;
        while(fast < nums.size()){
            if(nums[slow] != nums[fast])
                nums[++slow] = nums[fast];
            ++fast;
        }

        return slow + 1;
    }
};
