//
//  main.cpp
//  125_isPalindrome
//
//  Created by Bella Yang on 2019/10/15.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    bool isSame(char ch1, char ch2){
        if (isChar(ch1) ^ isChar(ch2)) {
            return false;
        }
        if (isChar(ch1) && isChar(ch2)) {
            return ch1 == ch2 || abs(ch1 - ch2) == abs('a' - 'A');
        }
        return ch1 == ch2;
    }
    bool isChar(char ch){
        return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
    }
    bool isNumber(char ch){
        return (ch >= '0' && ch <= '9');
    }
    bool isPalindrome(string s) {
        for (int i = 0, j = int(s.size() - 1); i < j; i++,j--) {
            while (i < s.size() && !isChar(s[i]) && !isNumber(s[i])) {
                i++;
            }
            while (j > -1 && !isChar(s[j]) && !isNumber(s[j])) {
                j--;
            }
            if (i == s.size() && j < 0) {
                return true;
            }
            if ((i == s.size() && j >= 0) || (i < s.size() && j < 0)) {
                return false;
            }
            if (!isSame(s[i], s[j])) {
                return false;
            }
        }
        return true;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.isPalindrome(".,");
    return 0;
}
