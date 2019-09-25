//
//  main.cpp
//  198_rob
//
//  Created by Bella Yang on 2019/9/25.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        int last_last = nums[0];
        int last = max(nums[0], nums[1]);
        int result;
        int i = 2;
        while (i < nums.size()) {
            result = max(last, last_last + nums[i]);
            last_last = last;
            last = result;
            i++;
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    const int LEN = 4;
    int array[LEN]={2, 1, 1, 2};
    vector<int>nums(array, array + LEN);
    cout << s.rob(nums) << endl;
    return 0;
}
