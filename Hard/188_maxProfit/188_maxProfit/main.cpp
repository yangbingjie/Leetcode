//
//  main.cpp
//  188_maxProfit
//
//  Created by Bella Yang on 2020/12/28.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        int profit = 0;
        if (k >= prices.size() / 2) {
            
            for (int i = 1; i < prices.size(); ++i) {
                if (prices[i] > prices[i - 1]) {
                    profit += prices[i] - prices[i - 1];
                }
            }
            return profit;
        }
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(k + 1, 0)));
        for (int j = 1; j <= k; ++j) {
            dp[0][1][j] = -prices[0];
        }
        for (int i = 1; i < prices.size(); ++i) {
            for (int j = 1; j <= k; ++j) {
                dp[i][0][j] = max(dp[i - 1][0][j], dp[i - 1][1][j] + prices[i]);
                dp[i][1][j] = max(dp[i - 1][1][j], dp[i - 1][0][j - 1] - prices[i]);
                profit = max(profit, max(dp[i][0][j], dp[i][1][j]));
            }
        }
        return profit;
    }
};
int main(int argc, const char * argv[]) {
    vector<int> prices = {3,2,6,5,0,3,0,6};
    Solution s;
    cout << s.maxProfit(2, prices) << endl;
    return 0;
}
