//
//  main.cpp
//  34_searchRange
//
//  Created by Bella Yang on 2019/9/3.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void searchRecur(vector<int>& result, vector<int>& nums, int start, int end, int target, int type){
        if (end <= start) {
            return;
        }
        int index = int((end - start) / 2 + start);
        if (nums[index] == target) {
            switch (type) {
                case -1:
                    result[0] = index;
                    searchRecur(result, nums, start, index, target, -1);
                    break;
                case 0:
                    result[0] = index;
                    result[1] = index;
                    searchRecur(result, nums, start, index, target, -1);
                    searchRecur(result, nums, index + 1, end, target, 1);
                    break;
                case 1:
                    result[1] = index;
                    searchRecur(result, nums, index + 1, end, target, 1);
                    break;
                default:
                    break;
            }
        }else if (nums[index] > target){
            searchRecur(result, nums, start, index, target, type);
        }else{
            searchRecur(result, nums, index + 1, end, target, type);
        }
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>result(2, -1);
        searchRecur(result, nums, 0, int(nums.size()), target, 0);
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    const int LEN = 2;
    int array[LEN] = {2, 2};
    vector<int> nums(array, array + LEN);
    s.searchRange(nums, 2);
    return 0;
}
