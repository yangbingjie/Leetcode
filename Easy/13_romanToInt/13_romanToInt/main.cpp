//
//  main.cpp
//  13_romanToInt
//
//  Created by Bella Yang on 2019/8/6.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
#include <iterator>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        const int LEN= 13;
        string name[LEN] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
        int value[LEN] = {     1,    4,   5,    9,  10,   40,  50,   90, 100,  400, 500,  900, 1000};
        
        int result = 0;
        
        for (int i = LEN - 1, j = 0; i >= 0 && j < s.length(); --i) {
            if (s.substr(j, name[i].length()) == name[i]) {
                result += value[i];
                j += name[i].length();
                
                if (j < s.length() && (i == 0 || i == 4 || i == 8 || i == 12) && s.substr(j, 1) == name[i]) {
                    i++;
                }
            }
        }
       
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.romanToInt("LVIII") << endl;
    return 0;
}
