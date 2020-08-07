//
//  main.cpp
//  Offer03_findRepeatNumber
//
//  Created by bella on 2020/8/7.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i) {
                if (nums[nums[i]]==nums[i]) {
                    return nums[i];
                }
                swap(nums[i], nums[nums[i]]);
            }
        }
        return -1;
    }
};
int main(int argc, const char * argv[]) {
    const int LEN = 7;
    int arr[LEN]={2, 3, 1, 0, 2, 5, 3};
    vector<int>nums(arr, arr +LEN);
    Solution s;
    cout <<s.findRepeatNumber(nums) << endl;
    return 0;
}
