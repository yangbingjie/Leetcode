//
//  main.cpp
//  12_intToRoman
//
//  Created by Bella Yang on 2019/8/5.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string result = "";
        const int LEN= 13;
        string name[LEN] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
        int value[LEN] = {     1,    4,   5,    9,  10,   40,  50,   90, 100,  400, 500,  900, 1000};
        for (int i = LEN - 1; num > 0; --i) {
            if (num >= value[i]) {
                num -= value[i];
                result += name[i];
            }
            // I, X, C M 可以出现多个，直到num小于它们四个的值为止
            if ((i == 0 || i == 4 || i == 8 || i == 12) && (num >= value[i])) {
                ++i;
            }
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.intToRoman(300) << endl;
    return 0;
}
