//
//  main.cpp
//  8_myAtoi
//
//  Created by Bella Yang on 2019/8/5.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int index = 0;
        
        // Remove the space before the number
        while (index < str.length() && str[index] == ' ') {
            index++;
        }
        
        // Check the first non-space char: -, +, 0~9
        if (index == str.length() || (str[index] != '-' && str[index] != '+' && (str[index] < 48 || str[index] > 57))) {
            return 0;
        }
        
        bool sign = true;
        // Check the sign of the number
        if (str[index] == '-' || str[index] == '+') {
            if (str[index] == '-') {
                sign = false;
            }
            index++;
        }
        
        int result = 0;
        // Check the first char (after the sign) is a number
        if (index != str.length() && str[index] >= 48 && str[index] <= 57) {
            result += str[index] - 48;
            index++;
        }else{
            return 0;
        }
        int offset;
        // Add the char until it is not a number
        for (;index != str.length(); ++index) {
            if (str[index] >= 48 && str[index] <= 57) {
                offset = str[index] - 48;
                if (result < 214748365) {
                    result *= 10;
                }else{
                    return sign ? 2147483647 : -2147483648;
                }
                if (!sign && result >= (2147483648 - offset)) {
                    return -2147483648;
                }
                if (sign && result  > (2147483647 - offset)) {
                    return 2147483647;
                }
                result += offset;
            }else{
                break;
            }
        }
        return sign ? result : -result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    cout << s.myAtoi("-91283472332") << endl;
    return 0;
}
