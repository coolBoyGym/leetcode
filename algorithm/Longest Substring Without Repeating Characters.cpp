#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int loc[256];   // ��������ַ���һ�γ��ֵ�λ�õ�������
        memset(loc, -1, sizeof(loc));

        int max = 0, idx = -1;  // max���ִ���󳤶� idx�ǵ�ǰ�ִ�����ʼλ�õ�ǰһ��λ��
        for(int i = 0; i < s.size(); ++i)
        {
            //����ǰ�ַ��ڵ�ǰ�ִ��г��ֹ� ���µ��ִ��ӵ�ǰ�ַ��ϴγ���λ�õ���һ����ʼ
            if(loc[s[i]] > idx)
                idx = loc[s[i]];
            //�����ִ���󳤶�
            if(i - idx > max)
                max = i - idx;
            //���µ�ǰ�ַ��ĳ���λ��
            loc[s[i]] = i;
        }

        return max;
    }
};
