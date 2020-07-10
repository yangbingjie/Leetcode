//
//  main.cpp
//  309_maxProfit
//
//  Created by bella on 2020/7/10.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 1) {
            return 0;
        }
        vector<vector<int>>dp(prices.size(), vector<int>(4));
        dp[0][0] = -prices[0];
        dp[0][1] = INT_MIN;
        dp[0][2] = 0;
        dp[0][3] = INT_MIN;
        for (int i = 1; i < prices.size(); ++i) {
            dp[i][0] = dp[i - 1][2] - prices[i];
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][3]) + prices[i];
            dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]);
            dp[i][3] = max(dp[i - 1][0], dp[i - 1][3]);
        }
        return max(dp[prices.size() - 1][1], dp[prices.size() - 1][2]);
    }
};
int main(int argc, const char * argv[]) {
    const int LEN = 5;
    int array[LEN] = {-3,-4,-9,-3,1};
    Solution s;
    vector<int>vec(array, array + LEN);
    cout <<s.maxProfit(vec) << endl;
    return 0;
}
