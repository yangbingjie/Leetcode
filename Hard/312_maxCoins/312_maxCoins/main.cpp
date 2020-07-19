//
//  main.cpp
//  312_maxCoins
//
//  Created by bella on 2020/7/19.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 2, vector<int>(n + 2));
        vector<int> val(n + 2);
        val[0] = val[n + 1] = 1;
        for (int i = 1; i < n + 1; ++i) {
            val[i] = nums[i - 1];
        }
        int tmp;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 2; j <= n + 1; ++j) {
                for (int k = i + 1; k < j; ++k) {
                    tmp = val[i] * val[k] * val[j] + dp[i][k] + dp[k][j];
                    dp[i][j] = max(dp[i][j], tmp);
                }
            }
        }
        return dp[0][n + 1];
    }
};
int main(int argc, const char * argv[]) {
    const int LEN = 4;
    int arr[LEN] = {3,1,5,8};
    vector<int>nums(arr, arr + LEN);
    Solution s;
    cout << s.maxCoins(nums) << endl;
    return 0;
}
