#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        string ans;
        int n = s.length();
        if(numRows == 1) return s;

        for(int i = 0; i < numRows; i++){
            int j = i;
            int r = 2 * i;
            int l = 2 * (numRows - 1);  // 每次的步长
            while(j < n){
                ans += s[j];
                if(i == 0 || i == (numRows - 1)){ // First and last row.
                    j += l;
                }
                else{
                    r = l - r;
                    j += r;
                }
            }
        }
        return ans;
    }
};
