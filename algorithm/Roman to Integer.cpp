#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// �������������ֵ��ַ���ת��Ϊʮ������
// �Ȱ���ÿ����ĸ��ֵȫ����� �ټ�����ʾ 9��90��900����һ����
// ע�⣺��leetcode��ʵ��ʱswitch�������Ҫ��һ��defaultѡ�� ������뱨��
class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        for(unsigned int i=0; i<s.size(); ++i)
            result += getNum(s[i]);

        int curr, pre;
        for(unsigned int j=0; j<s.size()-1; ++j)
        {
            pre = getNum(s[j]);
            curr = getNum(s[j+1]);
            if(pre * 5 == curr || pre * 10 == curr)
            {
                result -= pre * 2;
                ++j;
            }
        }

        return result;
    }

    int getNum(char c){
        switch(c)
        {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 1;
        }
    }
};
