//
//  main.cpp
//  238_productExceptSelf
//
//  Created by bella on 2020/8/14.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>result(nums.size(), 1);
        int left = 1;
        int right = 1;
        for(int i = 1; i < nums.size();++i){
            left *= nums[i - 1];
            result[i] *= left;
            right *= nums[nums.size() - i];
            result[nums.size() - 1 - i] *= right;
        }

        return result;
    }
};
int main(int argc, const char * argv[]) {
    const int LEN = 2;
    int arr[LEN] = {3,4};
    vector<int>vec(arr, arr + LEN);
    Solution s;
    s.productExceptSelf(vec);
    return 0;
}
