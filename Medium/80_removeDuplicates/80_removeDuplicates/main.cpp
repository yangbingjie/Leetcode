//
//  main.cpp
//  80_removeDuplicates
//
//  Created by Bella Yang on 2019/9/14.
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
        int count = 1;
        int len = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (value != nums[i]) {
                value = nums[i];
                nums[len] = value;
                len++;
                count = 1;
            }else if (count < 2){
                nums[len] = value;
                len++;
                count++;
            }
        }
        return len;
    }
};
int main(int argc, const char * argv[]) {
    const int LEN = 9;
    int array[LEN] = {0,0,1,1,1,1,2,3,3};
    vector<int> nums(array, array + LEN);
    Solution s;
    cout << s.removeDuplicates(nums) << endl;
    return 0;
}
