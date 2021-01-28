//
//  main.cpp
//  724_pivotIndex
//
//  Created by Bella Yang on 2021/1/28.
//

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if (nums.empty()) {
            return -1;
        }
        if (nums.size() == 1) {
            return 0;
        }
        vector<int>prefix(nums.size() + 2);
        prefix[0] = 0;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        for (int i = 1; i < nums.size(); ++i) {
            prefix[i] = prefix[i - 1] + nums[i - 1];
            if ((sum - nums[i - 1]) % 2 == 0 && prefix[i - 1] == (sum - nums[i - 1]) / 2) {
                return i - 1;
            }
        }
        if (sum - nums[nums.size() - 1] == 0) {
            return nums.size() - 1;
        }
        return -1;
    }
};
int main(int argc, const char * argv[]) {
    vector<int>nums = {-1,-1,0,1,1,0};
    Solution s;
    cout << s.pivotIndex(nums) <<endl;
    return 0;
}
