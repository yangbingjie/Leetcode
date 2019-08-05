//
//  main.cpp
//  8_myAtoi
//
//  Created by Bella Yang on 2019/8/5.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int index = 0;
        string result_str = "";
        
        // Remove the space before the number
        while (index < str.length() && str[index] == ' ') {
            index++;
        }
        
        // Check the first non-space char: -, +, 0~9
        if (index == str.length() || (str[index] != '-' && str[index] != '+' && (str[index] < 48 || str[index] > 57))) {
            return 0;
        }
        
        // Check the sign of the number
        if (str[index] == '-' || str[index] == '+') {
            result_str += str[index];
            index++;
        }
        
        // If the result is a number
        bool is_num = false;
        
        // Check the first char (after the sign) is a number
        if (index != str.length() && str[index] >= 48 && str[index] <= 57) {
            is_num = true;
            result_str += str[index];
            index++;
        }
        
        // Add the char until it is not a number
        for (;index != str.length(); ++index) {
            if (str[index] >= 48 && str[index] <= 57) {
                result_str += str[index];
            }else{
                break;
            }
        }
        
        // From string to long
        long result_num;
        stringstream s;
        s << result_str;
        s >> result_num;
        
        // Check for overflow
        if (result_num < -2147483648) {
            result_num = -2147483648;
        }
        if (result_num  > 2147483647) {
            result_num = 2147483647;
        }
        return int(result_num);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    cout << s.myAtoi("2147483648") << endl;
    return 0;
}
