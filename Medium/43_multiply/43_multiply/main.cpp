//
//  main.cpp
//  43_multiply
//
//  Created by bella on 2020/8/13.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    void add(string& result, int begin, int num){
        int carry = 0;
        int reminder;
        int sum;
        int ind = result.size() - 1 - begin;
        if (ind < 0) {
            result = to_string(num) + result;
            return;
        }
        while (ind >= 0) {
            sum = (result[ind] - '0') + num + carry;
            num = 0;
            reminder = sum % 10;
            carry = (sum - reminder) / 10;
            result[ind] = '0' + reminder;
            if (carry != 0) {
                ind--;
            }else{
                break;
            }
        }
        if (ind == -1 && carry != 0) {
            result = to_string(carry) + result;
        }
    }
    string multiply(string num1, string num2) {
        if ((num1.size() == 1 && stoi(num1) == 0) || (num2.size() == 1 && stoi(num2) == 0)) {
            return "0";
        }
        string result = "";
        int product;
        int reminder;
        int carry = 0;
        int j;
        for (int i = num1.size() - 1; i >= 0; i--) {
            for (j = num2.size() - 1; j >= 0; j--) {
                product = (num1[i] - '0') * (num2[j] - '0') + carry;
                reminder = product % 10;
                carry = (product - reminder) / 10;
                add(result, num1.size() + num2.size() - 2 - (i + j), reminder);
            }
            if (carry != 0) {
               add(result, num1.size() + num2.size() - 2 - (i + j), carry);
                carry = 0;
            }
        }
        return result;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.multiply("999", "999") << endl;
    return 0;
}
