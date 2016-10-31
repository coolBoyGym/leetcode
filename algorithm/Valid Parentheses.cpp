#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

// 简单的括号匹配问题 使用栈实现
class Solution {
public:
    bool isValid(string s) {
        stack<char> a;
        a.push('.');    // 此处先push一个无关字符 为了处理第一个字符是右括号的情况
        for (int i = 0; i < s.size(); i++) {
            switch (s[i]) {
                case '(':
                case '[':
                case '{': a.push(s[i]);break;
                case ')': if(a.top() != '(') return false;
                          else a.pop(); break;
                case ']': if(a.top() != '[') return false;
                          else a.pop(); break;
                case '}': if(a.top() != '{') return false;
                          else a.pop(); break;
            }
        }
        return (a.size() == 1);
    }
};

