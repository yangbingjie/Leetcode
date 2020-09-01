//
//  main.cpp
//  486_PredictTheWinner
//
//  Created by bella on 2020/9/1.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        vector<int>dp(nums.size());
        for (int i = 0; i < dp.size(); ++i) {
            dp[i] = nums[i];
        }
        
        for (int k = 1; k < dp.size(); ++k) {
            for (int i = 0, j = k; j < dp.size(); ++i, ++j) {
                dp[i] = max(nums[j] - dp[i], nums[i] - dp[i + 1]);
            }
        }
            
         
        return dp[0] >= 0;
    }
};
int main(int argc, const char * argv[]) {
    vector<int>vec = {1,5,2};
    Solution s;
    cout << s.PredictTheWinner(vec) << endl;
    return 0;
}
