//
//  main.cpp
//  1371_findTheLongestSubstring
//
//  Created by Bella Yang on 2020/5/20.
//  Copyright © 2020 Bella Yang. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    bool is_even(vector<vector<bool>>&prefix, int start, int end){
        for (int i = 0; i < 5; ++i) {
            if ((prefix[i][end] != prefix[i][start])) {
                return false;
            }
        }
        return true;
    }
    int findTheLongestSubstring(string s) {
        vector<vector<bool>> prefix(5, vector<bool>(s.size() + 1, false));
        for (int i = 0; i < s.size(); ++i) {
            for (int j = 0; j < 5; ++j) {
                prefix[j][i + 1] = prefix[j][i];
            }
            if (s[i] == 'a') {
                prefix[0][i + 1] = !prefix[0][i + 1];
            }else if (s[i] == 'e') {
                prefix[1][i + 1] = !prefix[1][i + 1];
            }else if (s[i] == 'i') {
                prefix[2][i + 1] = !prefix[2][i + 1];
            }else if (s[i] == 'o') {
                prefix[3][i + 1] = !prefix[3][i + 1];
            }else if (s[i] == 'u') {
                prefix[4][i + 1] = !prefix[4][i + 1];
            }
            
        }

        int max_len = 0;
        for (int len = s.size(); len > 0; --len) {
            for (int start = 0; start + len <= s.size(); ++start) {
                if (is_even(prefix, start, start + len)) {
                     return len;
                }
            }
        }
        return max_len;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.findTheLongestSubstring("leetcodeisgreat") << endl;
    return 0;
}
