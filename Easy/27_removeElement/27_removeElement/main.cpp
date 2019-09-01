//
//  main.cpp
//  27_removeElement
//
//  Created by Bella Yang on 2019/9/1.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty()) {
            return 0;
        }
        int left_index = 0;
        int right_index = int(nums.size() - 1);
        while (left_index <= right_index && left_index < nums.size() && right_index >= 0) {
            if (left_index == right_index) {
                if (nums[left_index] != val) {
                    left_index++;
                }else{
                    right_index--;
                }
                break;
            }
            while (right_index >= 0 && nums[right_index] == val) {
                right_index--;
            }
            if (left_index <= right_index) {
                while (left_index < nums.size() && left_index <= right_index && nums[left_index] != val) {
                    left_index++;
                }
                if (left_index < nums.size() && right_index >=0 && left_index <= right_index) {
                    nums[left_index] = nums[right_index];
                    left_index++;
                    right_index--;
                }
            }
        }
        if (left_index < nums.size() && left_index != right_index) {
            return left_index;
        }else{
            return int(nums.size());
        }
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    const int LEN = 4;
    int array[LEN] = {1, 2, 3, 4};
    vector<int> nums(array, array + LEN);
    cout << s.removeElement(nums, 1);
    return 0;
}
