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
        next[1] = 0; // A没有前后缀
        int i = 2; // i表示next数组的索引
        int k = 0;
        while (i < next.size()) {
            if (pattern[i - 1] == pattern[k]) { // pattern索引比next索引小1
                next[i] = k + 1;
                k = next[i];
                ++i;
            } else if (k == 0){
                next[i] = 0;
                ++i;
            } else{
                k = next[k];
            }
        }
        return next[next.size() - 1];
    }

    string shortestPalindrome(string s) {
        if(s == ""){
            return "";
        }
        string reverse_str(s.rbegin(), s.rend());
        string pattern = s + '#' + reverse_str;
        int max_len = commpute_next(pattern);
        return reverse_str.substr(0, reverse_str.size() - max_len) + s;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.shortestPalindrome("abcd") << endl;
    return 0;
}
