#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

// һ��nԪ���� ÿ��������һ�����ӵ�Ȩ�� ����Ҫ�����Ƿ��� Ҫ���ǣ�
// 1. ÿ�����������õ�һ����
// 2. ĳ������Ȩ�ر������ھӴ� ����Ҫ�õ�������
// �����������Ҫ���·ַ����ٵ��ǹ�

// ����ɨ�� ��һ��������� �ڶ���������� ÿ�αȽ���һ���������ڵ�Ȩ�ش�С �����и���
// ����ʵ�鷢�� ����ɨ����Ⱥ�˳����Ҫ
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int * candies = new int[n];
        for(int i = 0; i < n; ++i)
            candies[i] = 1;
        for(int i = n-1; i > 0; i--)
        {
            if(ratings[i-1] > ratings[i])
                candies[i-1] = candies[i] + 1;
        }
        for(int i = 0; i < n-1; ++i)
        {
            if(ratings[i+1] > ratings[i]){
                int tmp = candies[i] + 1;
                if(candies[i+1] < tmp)
                    candies[i+1] = tmp;
            }
        }

        int count = 0;
        for(int i = 0; i < n; ++i)
            count += candies[i];

        delete [] candies;
        return count;
    }

};
