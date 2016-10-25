#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;


class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;    // �洢���������

        int num = words.size();     // words���ִ��ĸ���
        int len = words[0].size();  // words��ÿ���ִ��ĳ���
        map<string, int> relation;    // words�е��ִ�<->��һ�γ��ֵ�λ��
        vector<int> dict;   // ��¼words��ÿһ����ͬ���ִ����ֵ���Ŀ
        int count = 0;      // words�в���ͬ���ִ��ĸ���

        //����words���ַ������ظ��������Ӧ�ı�� �Լ�ÿ������ַ������ֵĴ���
        for(int i = 0; i < num; i++)
        {
            map<string, int>::const_iterator got = relation.find(words[i]);
            if(got == relation.end())
            {
                pair<string, int> item(words[i], count);
                relation.insert(item);
                dict.push_back(1);
                count++;
            }
            else
                dict[got->second]++;
        }

        // ������̬�滮��������¼i��ʼ ����Ϊlen��S�ִ���words�ַ����Ĺ�ϵ
        int* sameWord = new int[s.size()];
        for(int i=0; i+len<=s.size(); i++)
        {
            map<string,int>::const_iterator got = relation.find(s.substr(i, len));
            if(got != relation.end())
                sameWord[i] = got->second;
            else
                sameWord[i] = -1;
        }

        // ��ͷ��ʼ���� ÿ�ζ��鿴����Ϊlen*num���ִ��ܷ񺭸����е�L�ִ�
        for(int k=0; k+len*num<=s.size(); k++)
        {
            int begin = k;
            vector<int> tmp = dict;
            bool found = true;
            int total = num;
            while(total > 0)
            {
                int index = sameWord[begin];

                if(index == -1)
                {
                    found = false;
                    break;
                }
                else
                {
                    if(tmp[index] > 0)
                    {
                        tmp[index]--;
                        total--;
                        begin+=len;
                    }
                    else
                    {
                        found = false;
                        break;
                    }
                }
            };

            if(found)
                res.push_back(k);
        }

        delete [] sameWord;
        return res;
    }
};

/*
// �뷨������index�������ж�
// ������������ һ��ĳ������������ǰ׺ʱ������ ��good/goods ���������дʵĳ�����ͬ
//              ���ǵ�words������ͬ������ ʹ��set�������жϷ��������
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if(words.empty() || words[0].size() < 1 || s.size() < words[0].size() * words.size())
            return res;

        int l = s.size(), m = words.size(), n = words[0].size();
        vector<int> indexes;
        for(int i = 0; i < l; ++i)
            indexes.push_back(-1);

        string curr;
        size_t found = size_t(0);
        for(int i = 0; i < m; ++i)
        {
            curr = words[i];
            found = size_t(0);
            while((found = s.find(curr, found)) != string::npos){
                int tmp = int(found);
                indexes[tmp] = i;
                found = found + 1;
            }
        }


        set<int> ss;
        for(int i = 0; i < l; ++i){
            if(indexes[i] != -1){
                ss.clear();
                ss.insert(indexes[i]);
                for(int j = 1; j < m; ++j){
                    int tmp = i + j * n;
                    if(tmp >= l || indexes[tmp] == -1)
                        break;
                    else
                        ss.insert(indexes[tmp]);
                }
                if(ss.size() == m)
                    res.push_back(i);
            }
        }

        return res;
    }
};
*/
