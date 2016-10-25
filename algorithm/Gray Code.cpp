#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ����һ��n ���nλ���������д������ֵ����
// �ݹ��˼�� ��С��ģ��ʼ������չ
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;

        if(n == 0)  // nΪ0ʱʵ������һ����������
        {
            result.push_back(0);
        } else {
            result = grayCode(n-1);
            int length = result.size();
            for(int i = length-1; i >= 0; i--)  // ������length���� �����λ������֮ǰ���жԳ�
                result.push_back(result[i] + (1 << (n - 1)));   // ��λ�����޸����λ
        }

        return result;
    }
};
