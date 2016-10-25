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
        vector<int> res;    // 存储结果的向量

        int num = words.size();     // words中字串的个数
        int len = words[0].size();  // words中每个字串的长度
        map<string, int> relation;    // words中的字串<->第一次出现的位置
        vector<int> dict;   // 记录words中每一个不同的字串出现的数目
        int count = 0;      // words中不相同的字串的个数

        //建立words中字符串（重复）与其对应的编号 以及每个编号字符串出现的次数
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

        // 建立动态规划方程来记录i开始 长度为len的S字串与words字符串的关系
        int* sameWord = new int[s.size()];
        for(int i=0; i+len<=s.size(); i++)
        {
            map<string,int>::const_iterator got = relation.find(s.substr(i, len));
            if(got != relation.end())
                sameWord[i] = got->second;
            else
                sameWord[i] = -1;
        }

        // 从头开始遍历 每次都查看长度为len*num的字串能否涵盖所有的L字串
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
// 想法是先求index数组再判断
// 遇到两个问题 一是某个词是其他词前缀时有问题 如good/goods 不过本题中词的长度相同
//              二是当words中有相同词语是 使用set个数的判断方法会出错
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
