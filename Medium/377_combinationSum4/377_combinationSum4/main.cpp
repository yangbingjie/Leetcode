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
        vector<unsigned int> sum(target, 0);
        for (int i = 0; i < nums.size() && nums[i] - 1 < target; ++i) {
            sum[nums[i] - 1] = 1;
        }
        for (int k = nums[0]; k < target; ++k) {
            for (int i = 0, j = k; i < nums.size() && j < target ; ++i, ++j) {
                if (j + 1 > nums[i]) {
                    sum[j] += sum[j - nums[i]];
                }
            }
        }
        return sum[target - 1];
    }
};
int main(int argc, const char * argv[]) {
    vector<int>nums = {1,2,3,4};
    Solution s;
    cout << s.combinationSum4(nums, 4) << endl;
    return 0;
}
