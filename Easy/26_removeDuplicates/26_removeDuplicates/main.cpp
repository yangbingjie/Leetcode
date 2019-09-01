//
//  main.cpp
//  26_removeDuplicates
//
//  Created by Bella Yang on 2019/9/1.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int value = nums[0];
        int old_index = 1;
        int new_index = 1;
        while (old_index < nums.size()) {
            if (value < nums[old_index]) {
                value = nums[old_index];
                nums[new_index] = value;
                new_index++;
            }
            old_index++;
        }
        nums.resize(new_index);
        return new_index;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    const int LEN = 3;
    int array [LEN] = {1, 1, 2};
    vector<int>nums(array, array + LEN);
    cout << s.removeDuplicates(nums);
    return 0;
}
