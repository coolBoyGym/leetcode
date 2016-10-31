#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

// �򵥵�����ƥ������ ʹ��ջʵ��
class Solution {
public:
    bool isValid(string s) {
        stack<char> a;
        a.push('.');    // �˴���pushһ���޹��ַ� Ϊ�˴����һ���ַ��������ŵ����
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

