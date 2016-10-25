#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 将代表罗马数字的字符串转化为十进制数
// 先按照每个字母的值全部相加 再减掉表示 9，90，900的那一部分
// 注意：在leetcode上实测时switch语句中需要加一个default选项 否则编译报错
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
