//
//  main.cpp
//  214_shortestPalindrome
//
//  Created by bella on 2020/8/29.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int commpute_next(string pattern){
        vector<int>next(pattern.size() + 1, 0);
        next[0] = -1;
        for (int i = 2; i < next.size(); ++i) {
            for (int j = 1; j < i; ++j) {
                if (pattern.substr(0, j) == pattern.substr(i - j, j)) {
                    next[i] = j;
                }
            }
        }
        return next[pattern.size()];
    }

    string shortestPalindrome(string s) {
        if(s == ""){
            return "";
        }
        string reverse = "";
        for (int i = s.size() - 1; i >= 0; --i) {
            reverse += s[i];
        }
        
        string pattern = s + '#' + reverse;
        int max_len = commpute_next(pattern);
        return reverse.substr(0, reverse.size() - max_len) + s;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.shortestPalindrome("abcd") << endl;
    return 0;
}
