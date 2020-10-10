//
//  main.cpp
//  416_canPartition
//
//  Created by Bella Yang on 2020/10/10.
//

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 != 0 || nums.size() == 1){
            return false;
        }
        sum /= 2;
        vector<vector<bool>>dp(nums.size(), vector<bool>(sum + 1, false));
        if (nums[0] < sum) {
            dp[0][nums[0]] = true;
        }
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < sum + 1; ++j) {
                if (dp[i - 1][j] || nums[i] == j || (j - nums[i] >= 0 && j - nums[i] < sum + 1 && dp[i - 1][j - nums[i]])) {
                    dp[i][j] = true;
                }
            }
        }
        return dp[nums.size() - 1][sum];
    }
};
int main(int argc, const char * argv[]) {
    vector<int>nums = {55,49,68,50,25,8,85,42,11,32,2,91,30,48,66,11,28,41,20,1,54,48,18,47,42,23,42,67,71,90,15,49,21,25,43,65,73,76,10,44,14,5,97,30,39,31,90,2,78,37,5,47,3,23,47,45,53,3,77,92,32,34,73,65,28,73,19,52,2,46,41,96,14,51,50,48,30,22,15,35,29,61,79,25,64,2,20,24,4,62,20,71,9,14,88,66,81,87,29,99};
    Solution s;
    cout << s.canPartition(nums) << endl;
    return 0;
}
