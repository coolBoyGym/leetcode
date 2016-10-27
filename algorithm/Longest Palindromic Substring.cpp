#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
using namespace std;

// ����һ���ַ��� �ҳ���Ļ����ִ�
// �������е��ص㣺
//      ������Ϊ���� ������м�һ����ʼ��������չ ��Ӧλ���ַ���ͬ
//      ������Ϊż�� �����м������ַ��ض���ͬ
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty()) return "";
        if(s.size() == 1) return s;
        int min_start = 0, max_length = 1, n = s.size();
        for(int i = 0; i < n; ){
            if(n - i <= max_length / 2) break;  // ���㽫ʣ�µ��ַ�����Ϊ���ĵ�һ����Ҳ�޷�����
            int k = i, j = i;
            while(k < n - 1 && s[k+1] == s[k]) ++k;  //  Խ���ظ���Ԫ��
            i = k + 1;  // ��һ�αȽϵĳ�����
            while(k < n -1 && j > 0 && s[k+1] == s[j-1]){ j--; k++; }
            int new_length = k - j + 1;     // k��j�ֱ����µ���������е���ʼλ��
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
