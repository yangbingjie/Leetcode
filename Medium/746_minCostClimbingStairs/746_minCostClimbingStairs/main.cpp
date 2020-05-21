//
//  main.cpp
//  746_minCostClimbingStairs
//
//  Created by Bella Yang on 2020/5/21.
//  Copyright © 2020 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int last_cost = 0;
        int last_last_cost = 0;
        int current_cost = 0;
        for (int i = 1; i < cost.size(); ++i) {
            current_cost = min(last_cost + cost[i], last_last_cost + cost[i - 1]);
            last_last_cost = last_cost;
            last_cost = current_cost;
        }
        return current_cost;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    const int LEN = 10;
//    int arr[LEN] = {10, 15, 20};
    int arr[LEN] = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    vector<int>cost(arr, arr + LEN);
    cout << s.minCostClimbingStairs(cost) << endl;
    return 0;
}
