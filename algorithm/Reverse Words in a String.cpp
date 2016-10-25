#include <iostream>
#include <stack>
#include <string>
using namespace std;

// ͨ������ջ�����ʵ�ֵ���
class Solution {
public:
    void reverseWords(string &s) {
        stack<int> word;
        stack<int> sentence;
        int i = 0;

        while(i <= s.size()){
            if(i == s.size() || s[i] == ' '){   // i==size ��Ϊ��ʹ�����һ������Ҳ����ջ
                if(!word.empty()){
                    if(!sentence.empty()){
                        sentence.push(' ');
                    }
                    while(!word.empty()){
                        sentence.push(word.top());
                        word.pop();
                    }
                }
            } else{     // ����һ���������ַ� ���ǿո�
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
