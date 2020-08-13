//
//  main.cpp
//  1365_smallerNumbersThanCurrent
//
//  Created by bella on 2020/8/12.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int>result(nums.size());
        int count[101] = {0};
        for (int i = 0; i < nums.size(); ++i) {
            count[nums[i]]++;
        }
        for (int i = 1; i < 101; ++i) {
            count[i] += count[i - 1];
        }
        for (int i = 0; i < result.size(); ++i) {
            if(nums[i] - 1 >= 0){
                result[i] = count[nums[i] - 1];
            }else{
                result[i] = 0;
            }
        }
        return result;
    }
};
int main(int argc, const char * argv[]) {
    const int LEN = 6;
    int arr[LEN] = {5,0,10,0,10,6};
    vector<int>nums(arr, arr + LEN);
    Solution s;
    s.smallerNumbersThanCurrent(nums);
    return 0;
}
