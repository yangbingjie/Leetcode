//
//  main.cpp
//  714_maxProfit
//
//  Created by Bella Yang on 2020/12/17.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<int> yesterday(2);
        vector<int> today(2);
        yesterday[0] = 0;
        yesterday[1] = -prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            today[0] = max(yesterday[0], yesterday[1] - fee + prices[i]);
            today[1] = max(yesterday[0] - prices[i], yesterday[1]);
            swap(today, yesterday);
        }
        return yesterday[0];
    }
};
int main(int argc, const char * argv[]) {
    vector<int> prices = {1, 3, 2, 8, 4, 9};
    Solution s;
    cout << s.maxProfit(prices, 2) << endl;
    return 0;
}
