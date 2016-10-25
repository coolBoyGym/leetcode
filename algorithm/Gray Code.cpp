#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 给定一个n 输出n位格雷码序列代表的数值数组
// 递归的思想 从小规模开始不断扩展
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;

        if(n == 0)  // n为0时实际上是一个特殊情形
        {
            result.push_back(0);
        } else {
            result = grayCode(n-1);
            int length = result.size();
            for(int i = length-1; i >= 0; i--)  // 新生成length个数 除最高位以外与之前序列对称
                result.push_back(result[i] + (1 << (n - 1)));   // 移位操作修改最高位
        }

        return result;
    }
};
