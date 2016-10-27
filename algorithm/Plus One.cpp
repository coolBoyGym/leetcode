#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    // add one slot to the beginning of the vector
    void resize(vector<int>& digits) {
    	digits.push_back(0);
    	// moving right all elements
    	for (int i = digits.size() - 1; i > 0; --i) {
    		digits[i] = digits[i-1];
    	}
    	digits[0] = 0;
    }

    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size() - 1;
        ++digits[n];
        while (digits[n] > 9) {
            if (n == 0) {
            	resize(digits);
            	++n;
            }
            digits[n] = 0;
            ++digits[--n];
        }
        return digits;
    }
};
