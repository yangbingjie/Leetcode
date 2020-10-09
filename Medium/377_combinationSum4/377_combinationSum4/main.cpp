//
//  main.cpp
//  377_combinationSum4
//
//  Created by Bella Yang on 2020/10/9.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        if (nums.empty()) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        vector<vector<int>> dp(nums.size(), vector<int>(target + 1, 0));
        vector<int> sum(target + 1, 0);
        for (int i = 0; i < nums.size() && nums[i] <= target; ++i) {
            dp[i][nums[i]] = 1;
            sum[nums[i]] = 1;
        }
        for (int k = nums[0] + 1; k <= target; ++k) {
            for (int i = 0, j = k; i < nums.size() && j <= target ; ++i, ++j) {
                if (dp[i][j] == 0 && j > nums[i]) {
                    dp[i][j] = sum[j - nums[i]];
                    sum[j] += dp[i][j];
                }
            }
        }
        return sum[target];
    }
};
int main(int argc, const char * argv[]) {
    vector<int>nums = {9};
    Solution s;
    cout << s.combinationSum4(nums, 3) << endl;
    return 0;
}
