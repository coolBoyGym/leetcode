#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
using namespace std;

// 给定一个字符串 找出最长的回文字串
// 回文序列的特点：
//      若长度为奇数 则从最中间一个开始向两边扩展 对应位置字符相同
//      若长度为偶数 则最中间两个字符必定相同
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty()) return "";
        if(s.size() == 1) return s;
        int min_start = 0, max_length = 1, n = s.size();
        for(int i = 0; i < n; ){
            if(n - i <= max_length / 2) break;  // 就算将剩下的字符都作为回文的一部分也无法超过
            int k = i, j = i;
            while(k < n - 1 && s[k+1] == s[k]) ++k;  //  越过重复的元素
            i = k + 1;  // 下一次比较的出发点
            while(k < n -1 && j > 0 && s[k+1] == s[j-1]){ j--; k++; }
            int new_length = k - j + 1;     // k和j分别是新的最长回文序列的起始位置
            if(new_length > max_length){ max_length = new_length; min_start = j; }
        }

        return s.substr(min_start, max_length);
    }
};

/*
class Solution {
public:
    string longestPalindrome(string s) {
        set<string> m;
        string res = "";
        int n = s.size();
        int max_length = 0;
        for(int i = 1; i <= n / 2; ++i){
            for(int j = 0; j + i <= n; ++j)
            {
                string temp = s.substr(j, i);
                if(!m.count(temp))
                    m.insert(temp);
                else{
                    if(i > max_length){
                        max_length = i;
                        res = temp;
                    }
                }

            }
        }

        return res;
    }
};
*/
