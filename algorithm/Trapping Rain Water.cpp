#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// �ؼ��������ҵ���ߵ��Ǹ����� Ȼ������߷ֱ������λ�ý��б���
// �ڱ��������� һ�������п���עˮ�ĵط���עˮ ��ߵ��Ǹ����ӱ�֤����Щˮ��������
// ����Ҫ�ľ����ҵ����߶� �����Ϳ��Թ̶�һ�� ��һ��ֻҪ�߶�����Ϳ���עˮ
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n <= 2)
            return 0;

        int i, max = height[0], max_index = 0;
        for(i = 1; i < n; ++i)
            if(height[i] > max){
                max = height[i];
                max_index = i;
            }

        int water = 0, curr_height = 0; // water�ǵ�ǰ��עˮ�� curr_height�ǵ�ǰ��עˮ�����߶�
        for(i = 0; i < max_index; i++)
        {
            if(curr_height >= height[i])
                water += curr_height - height[i];    // ���ݵ�ǰ���߶����λ�õĲ�ֵ����עˮ
            else
                curr_height = height[i];     // ���ָ���ĸ߶� ���¸�ֵ
        }

        curr_height = 0;    // ����һ������ʼעˮ
        for(i = n-1; i > max_index; i--)
        {
            if(curr_height >= height[i])
                water += curr_height - height[i];
            else
                curr_height = height[i];
        }

        return water;   // �������յ�עˮ��
    }
};
