//
//  main.cpp
//  645_findErrorNums
//
//  Created by bella on 2020/8/11.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int>result;
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] != i + 1) {
                if (nums[i] == nums[nums[i] - 1]) {
                    break;
                }
                swap(nums[i], nums[nums[i] - 1]);
            }else{
                ++i;
            }
        }
        result.push_back(nums[i]);
        int miss = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            miss ^= i;
            miss ^= nums[i];
        }
        miss ^= nums.size();
        miss ^= result[0];
        result.push_back(miss);
        return result;
    }
};
int main(int argc, const char * argv[]) {
//    const int LEN = 8;
//    int arr[LEN] = {8,7,3,5,3,6,1,4};
    const int LEN = 4;
    int arr[LEN] = {1,2,2,4};
    vector<int>nums(arr, arr +LEN);
    Solution s;
    s.findErrorNums(nums);
    return 0;
}
