//
//  main.cpp
//  448_findDisappearedNumbers
//
//  Created by Bella Yang on 2021/2/13.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int>result;
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] == i + 1 || nums[nums[i] - 1] == nums[i]) {
                i++;
                continue;
            }
            swap(nums[i], nums[nums[i] - 1]);
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i + 1) {
                result.push_back(i + 1);
            }
        }
        return result;
    }
};
int main(int argc, const char * argv[]) {
    vector<int> nums = {4,3,2,7,8,2,3,1};
    Solution s;
    s.findDisappearedNumbers(nums);
    return 0;
}
