//
//  main.cpp
//  283_moveZeroes
//
//  Created by Bella Yang on 2019/11/23.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int fast = 0;
        int slow = 0;
        while (fast < nums.size()) {
            if (nums[fast] != 0) {
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }
        while (slow < nums.size()) {
            nums[slow] = 0;
            slow++;
        }
    }
};

int main(int argc, const char * argv[]) {
    const int LEN = 5;
    int array[LEN] = {0,1,0,3,12};
    vector<int> nums(array, array + LEN);
    Solution s;
    s.moveZeroes(nums);
    return 0;
}
