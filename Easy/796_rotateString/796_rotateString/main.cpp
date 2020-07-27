//
//  main.cpp
//  796_rotateString
//
//  Created by bella on 2020/7/27.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    bool kmp(string str, string pattern){
        vector<int>diff(pattern.size(), 0);
        for (int i = 1; i < diff.size(); ++i) {
            for (int j = 1; j < i; ++j) {
                if (pattern.substr(0, j) == pattern.substr(i - j + 1, j)) {
                    diff[i] = j;
                }
            }
        }
        int i = 0;
        int j = 0;
        
        while (i < str.size()) {
            while (j == 0 && i < str.size() && str[i] != pattern[j]) {
                i++;
            }
            while (j < pattern.size() && i < str.size() && str[i] == pattern[j]) {
                i++;
                j++;
            }
            if (j == pattern.size()) {
                return true;
            }else{
                if (j - 1 >= 0) {
                    j = j - (j - diff[j - 1]);
                }
            }
        }
        return false;
    }
    bool rotateString(string A, string B) {
        if (A.size() != B.size()) {
            return false;
        }
        if (A == "" && B == "") {
            return true;
        }
        return kmp(A + A, B);
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.rotateString("abcde", "abced") << endl;
    return 0;
}
