#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 将两个二进制数相加
class Solution {
public:
    string addBinary(string a, string b) {
        string reval(a.size() + b.size(), '0');
        int i(a.size()-1), j(b.size()-1), k(reval.size()-1), carry(0);
        while(i>=0 || j>=0 || carry){
            int sum(0);
            if(i >= 0) sum += a[i--] - '0';
            if(j >= 0) sum += b[j--] - '0';
            if(carry) sum += carry;
            reval[k--] = '0' + (sum % 2);
            carry = sum / 2;
        }
        std::size_t pos = reval.find_first_not_of('0');
        return pos == std::string::npos ? "0" : reval.substr(pos);
    }
};
