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
        int profit = 0;
        int i = 0;
        int j = int(prices.size() - 1);
        while (i + 1 < prices.size() && prices[i] >= prices[i + 1]) {
            i++;
        }
        if (i + 1 == prices.size()) {
            return 0;
        }
        while (j - 1 >= 0 && prices[j - 1] >= prices[j]) {
            j--;
        }
        int tmp;
        for (int a = i; a < j; ++a) {
            for (int b = a + 1; b <= j; ++b) {
                tmp = prices[b] - prices[a];
                if (tmp > profit) {
                    profit = tmp;
                }
            }
        }
        return profit;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    const int LEN = 5;
    int array[LEN] = {2,1,2,0,1};
    vector<int>prices(array, array + LEN);
    cout << s.maxProfit(prices) << endl;
    return 0;
}
