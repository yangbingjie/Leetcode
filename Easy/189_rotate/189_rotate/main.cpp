//
//  main.cpp
//  189_rotate
//
//  Created by Bella Yang on 2019/11/10.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        if (k == 0) {
            return;
        }
        reverse(nums.begin(), nums.end()-k);
        reverse(nums.end() - k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    const int LEN = 3;
    int array[LEN] = {1,2,3};
    vector<int> nums(array, array + LEN);
    s.rotate(nums, 2);
    return 0;
}
