//
//  main.cpp
//  287_findDuplicate
//
//  Created by Bella Yang on 2020/5/26.
//  Copyright © 2020 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] == nums[i + 1]) {
                return nums[i];
            }
        }
        return -1;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    const int LEN = 5;
    int arr[LEN]={1,3,4,2,2};
    vector<int>nums(arr, arr + LEN);
    cout << s.findDuplicate(nums) << endl;
    return 0;
}
