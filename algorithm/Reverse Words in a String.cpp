#include <iostream>
#include <stack>
#include <string>
using namespace std;

// 通过两个栈的组合实现倒序
class Solution {
public:
    void reverseWords(string &s) {
        stack<int> word;
        stack<int> sentence;
        int i = 0;

        while(i <= s.size()){
            if(i == s.size() || s[i] == ' '){   // i==size 是为了使得最后一个单词也能入栈
                if(!word.empty()){
                    if(!sentence.empty()){
                        sentence.push(' ');
                    }
                    while(!word.empty()){
                        sentence.push(word.top());
                        word.pop();
                    }
                }
            } else{     // 这是一个正常的字符 不是空格
                word.push(s[i]);
            }
            ++i;
        }

        s.clear();
        while(!sentence.empty()){
            s.push_back(sentence.top());
            sentence.pop();
        }

    }
};
