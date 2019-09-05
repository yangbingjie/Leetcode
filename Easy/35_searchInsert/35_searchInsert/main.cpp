//
//  main.cpp
//  35_searchInsert
//
//  Created by Bella Yang on 2019/9/4.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0;
        int end = int(nums.size());
        int mid;
        while (end > start) {
            mid = int((end + start) / 2);
            if (nums[mid] == target) {
                return mid;
            }else if (nums[mid] < target){
                start = mid + 1;
            }else{
                end = mid;
            }
        }
        return start;
    }
};

int main(int argc, const char * argv[]) {
    const int LEN = 4;
    int array[LEN] = {1, 3, 5, 7};
    vector<int>nums(array, array + LEN);
    Solution s;
    cout << s.searchInsert(nums, 8);
    return 0;
}
