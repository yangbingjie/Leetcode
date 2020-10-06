//
//  main.cpp
//  18_fourSum
//
//  Created by Bella Yang on 2020/10/5.
//

#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution {
private:
    vector<int>tmp;
public:
    void bp(int sum, vector<vector<int>>&result, vector<int>& nums, int target, int index, bool is_used, int n){
        if (n == 0) {
            if (sum == target) {
                sort(tmp.begin(), tmp.end());
                result.push_back(vector<int>(tmp));
            }
            return;
        }
        if (index + n > nums.size()) {
            return;
        }
        int min_num = sum;
        int max_num = sum;
        for (int i = 0; i < n; ++i) {
            min_num += nums[i];
            max_num += nums[nums.size() - i - 1];
        }
        if (min_num > target || max_num < target) {
            return;
        }
        if (is_used || index == 0 || nums[index] != nums[index - 1]) {
            sum += nums[index];
            tmp.push_back(nums[index]);
            bp(sum, result, nums, target, index+1, true, n - 1);
            tmp.pop_back();
            sum -= nums[index];
        }
        bp(sum, result, nums, target, index+1, false, n);
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>s;
        bp(0, s, nums, target, 0, false, 4);
        return s;
    }
};
int main(int argc, const char * argv[]) {
    vector<int>nums = {1, 0, -1, 0, -2, 2};
    Solution s;
    s.fourSum(nums, 0);
    return 0;
}
