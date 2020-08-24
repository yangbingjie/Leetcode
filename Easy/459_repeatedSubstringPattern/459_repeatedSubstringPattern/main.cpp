//
//  main.cpp
//  459_repeatedSubstringPattern
//
//  Created by bella on 2020/8/24.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int end = 1;
        bool is_all_repeated;
        while (end < s.size()) {
            while (end < s.size() && s[end] != s[0]) {
                end++;
            }
            if (end >= s.size()) {
                break;
            }
            if (s.size() % end != 0) {
                end++;
                continue;
            }
            is_all_repeated = true;
            for (int i = 1; i < s.size() / end; ++i) {
                for (int j = 0; j < end; ++j) {
                    if (s[end * i + j] != s[j]) {
                        is_all_repeated = false;
                        break;
                    }
                }
            }
            if (is_all_repeated) {
                return true;
            }
            end++;
        }
        return false;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.repeatedSubstringPattern("aba") << endl;
    return 0;
}
