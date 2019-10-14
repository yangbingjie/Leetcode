//
//  main.cpp
//  121_maxProfit
//
//  Created by Bella Yang on 2019/10/14.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        vector<int> profit(prices.size());
        profit[0] = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            profit[i] = min(profit[i - 1], prices[i]);
        }
        int end_index = int(prices.size() - 1);
        profit[end_index] = prices[end_index] - profit[end_index];
        for (int i = end_index - 1; i >= 0; --i) {
            profit[i] = max(profit[i + 1], prices[i]) - profit[i];
        }

        return *max_element(profit.begin(), profit.end());
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    const int LEN = 2;
    int array[LEN] = {1,2};
    vector<int>prices(array, array + LEN);
    cout << s.maxProfit(prices) << endl;
    return 0;
}
