//
//  main.cpp
//  55_find_zero
//
//  Created by Bella Yang on 2020/5/2.
//  Copyright © 2020 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() <= 1) {
            return true;
        }
        vector<int>zero_pos;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                zero_pos.push_back(i);
            }
        }
        if (zero_pos.size() == 0) {
            return true;
        }
        bool can_jump;
        for (int i = 0; i < zero_pos.size(); ++i) {
            can_jump = false;
            if (zero_pos[i] == nums.size() - 1) {
                return true;
            }
            for (int j = zero_pos[i] - 1; j >= 0; --j) {
                if (nums[j] > zero_pos[i] - j) {
                    can_jump = true;
                    break;
                }
            }
            if (!can_jump) {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    const int LEN = 3;
    int arr[LEN] = {2,0,0};
//    int arr[LEN] = {3,2,1,0,4};
//    int arr[LEN] = {2,3,1,1,4};
    vector<int> vec(arr, arr + LEN);
    Solution s;
    cout << s.canJump(vec) << endl;
    return 0;
}

