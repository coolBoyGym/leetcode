#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int loc[256];   // 存放所有字符上一次出现的位置的索引表
        memset(loc, -1, sizeof(loc));

        int max = 0, idx = -1;  // max是字串最大长度 idx是当前字串的起始位置的前一个位置
        for(int i = 0; i < s.size(); ++i)
        {
            //若当前字符在当前字串中出现过 则新的字串从当前字符上次出现位置的下一个开始
            if(loc[s[i]] > idx)
                idx = loc[s[i]];
            //更新字串最大长度
            if(i - idx > max)
                max = i - idx;
            //更新当前字符的出现位置
            loc[s[i]] = i;
        }

        return max;
    }
};
