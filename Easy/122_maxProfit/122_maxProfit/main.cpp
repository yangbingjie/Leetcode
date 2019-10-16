//
//  main.cpp
//  122_maxProfit
//
//  Created by Bella Yang on 2019/10/14.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        int profit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] > prices[i - 1]) {
                profit += prices[i] - prices[i - 1];
            }
        }
        return profit;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    const int LEN = 6;
    int array[LEN] = {7, 1,5,3,6,4};
    vector<int>prices(array, array + LEN);
    cout << s.maxProfit(prices) << endl;
    return 0;
}
