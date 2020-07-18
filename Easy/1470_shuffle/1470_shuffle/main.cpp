//
//  main.cpp
//  1470_shuffle
//
//  Created by bella on 2020/7/18.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>result(nums.size());
        for (int i = 0; i < n; ++i) {
            result[2 * i] = nums[i];
            result[2 * i + 1] = nums[n + i];
        }
        return result;
    }
};
int main(int argc, const char * argv[]) {
    const int LEN = 6;
    int arr[LEN] = {2,5,1,3,4,7};
    vector<int>nums(arr, arr + LEN);
    Solution s;
    s.shuffle(nums, 3);
    return 0;
}
