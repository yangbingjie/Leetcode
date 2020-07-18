//
//  main.cpp
//  97_isInterleave
//
//  Created by bella on 2020/7/18.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }
        vector<vector<bool>>dp(s1.size() + 1, vector<bool>(s2.size() + 1, false));
        dp[0][0] = true;
        for (int i = 1; i < s1.size() + 1; ++i) {
            if (dp[i - 1][0] && s1[i - 1] == s3[i - 1]) {
                dp[i][0] = true;
            }
        }
        for (int j = 1; j < s2.size() + 1; ++j) {
            if (dp[0][j - 1] && s2[j - 1] == s3[j - 1]) {
                dp[0][j] = true;
            }
        }
        for (int i = 1; i < s1.size() + 1; ++i) {
            for (int j = 1; j < s2.size() + 1; ++j) {
                if (dp[i][j - 1] && s2[j - 1] == s3[j + i - 1]) {
                    dp[i][j] = true;
                }else if (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) {
                    dp[i][j] = true;
                }
            }
        }
        return dp[s1.size()][s2.size()];
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.isInterleave("bacc", "aabcce", "abaacbccec") << endl;
    return 0;
}
