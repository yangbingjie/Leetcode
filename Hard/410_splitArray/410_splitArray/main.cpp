//
//  main.cpp
//  410_splitArray
//
//  Created by bella on 2020/7/25.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        vector<vector<long>>dp(m, vector<long>(nums.size(), INT_MAX));
        dp[0][0] = nums[0];
        for (int j = 1; j < nums.size(); ++j) {
            dp[0][j] = dp[0][j - 1] + nums[j];
        }
        for (int i = 1; i < m; ++i) {
            dp[i][i] = max(dp[i - 1][i - 1], (long)nums[i]);
        }
        int tmp;
        for (int i = 1; i < m; ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                tmp = 0;
                for (int k = 1; j - k >= 0; k++) {
                    tmp += nums[j - k + 1];
                    dp[i][j] = min(dp[i][j], max(dp[i - 1][j - k], (long)tmp));
                }
            }
        }
        return dp[m - 1][nums.size() - 1];
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    const int LEN = 5;
    int arr[LEN] = {7,2,5,10,8};
    vector<int>vec(arr, arr + LEN);
    cout << s.splitArray(vec, 2) << endl;
    return 0;
}
