//
//  main.cpp
//  33_search
//
//  Created by Bella Yang on 2019/9/3.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int binarySearch(vector<int>& nums, int start, int end, int target){
        int mid;
        while (end > start) {
            mid = int((start + end) / 2);
            if (nums[mid] == target) {
                return mid;
            }else if (nums[mid] < target){
                start = mid + 1;
            }else{
                end = mid;
            }
        }
        return -1;
    }
    int findBoundary(vector<int>& nums, int start, int end){
        int mid;
        while (end > start) {
            mid = int((start + end) / 2);
            if (nums[0] > nums[mid]) {
                end = mid;
            }else{
                start = mid + 1;
            }
        }
        if (start == nums.size() - 1 && nums[start] > nums[0]) {
            return -1;
        }
        return start;
    }
    int search(vector<int>& nums, int target) {
        if (nums.size() <= 1) {
            if (nums.size() == 1 && nums[0] == target) {
                return 0;
            }else{
                return -1;
            }
        }
        int boundary = findBoundary(nums, 1, int(nums.size() - 1));
        int result;
        if (boundary == -1) {
            result = binarySearch(nums, 0, int(nums.size()), target);
        }else if(nums[0] > target){
            result = binarySearch(nums, boundary, int(nums.size()), target);
        }else{
            result = binarySearch(nums, 0, boundary, target);
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    const int LEN = 2;
    int array[LEN] = {2,1};
    vector<int>nums(array, array + LEN);
    cout << s.search(nums, 1) << endl;
    return 0;
}
