//
//  main.cpp
//  680_validPalindrome
//
//  Created by Bella Yang on 2020/5/19.
//  Copyright © 2020 Bella Yang. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    bool recurValidPalindrome(string s) {
        for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
            if (s[i] != s[j]) {
                return recurValidPalindrome(s.substr(i + 1, j - i)) || recurValidPalindrome(s.substr(i, j - i));
            }
        }
        return true;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.validPalindrome("acewwxca") << endl;
    return 0;
}
