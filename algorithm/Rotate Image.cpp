#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 原地置换算法 寻找转换前后的位置关系 (x',y') = (-y, x)
class Solution {
public:
    void rotate(vector<vector<int> >& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n/2; ++i){
            for(int j = i; j < n - 1 - i; ++j){
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n-1-j][i];
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
                matrix[j][n-1-i] = tmp;
            }
        }
    }
};
