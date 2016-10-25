#include <iostream>
#include <string>
using namespace std;

// 有限状态机 构造转换表 根据最终状态判断是否数字
class Solution {
public:
    bool isNumber(string s) {
        enum InputType{
            INVALID,
            SPACE,
            SIGN,
            DIGIT,
            DOT,
            EXP,

            INPUT_NUM,
        };

        int transport_table[][INPUT_NUM] = {
            -1,  0,  3,  1,  2, -1,
            -1,  8, -1,  1,  4,  5,
            -1, -1, -1,  4, -1, -1,
            -1, -1, -1,  1,  2, -1,
            -1,  8, -1,  4, -1,  5,
            -1, -1,  6,  7, -1, -1,
            -1, -1, -1,  7, -1, -1,
            -1,  8, -1,  7, -1, -1,
            -1,  8, -1, -1, -1, -1,
        };

        int state = 0, i = 0;
        while(s[i] != '\0'){
            InputType inputType = INVALID;
            if(s[i] == ' ') inputType = SPACE;
            if(s[i] == '+' || s[i] == '-') inputType = SIGN;
            if(isdigit(s[i])) inputType = DIGIT;
            if(s[i] == '.') inputType = DOT;
            if(s[i] == 'e' || s[i] == 'E') inputType = EXP;

            state = transport_table[state][inputType];
            if(state == -1)
                return false;
            else
                ++i;
        }

        if(state == 1 || state == 4 || state == 7 || state == 8)
            return true;
        else
            return false;
    }
};
