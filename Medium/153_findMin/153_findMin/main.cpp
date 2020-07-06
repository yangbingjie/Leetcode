//
//  main.cpp
//  153_findMin
//
//  Created by bella on 2020/7/6.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        int begin = 0;
        int end = nums.size();
        int mid = int((end - begin) / 2) + begin;
        while (begin + 2 < end) {
            if (nums[mid] < nums[nums.size() - 1]) {
                end = mid + 1;
            }else if (nums[mid] > nums[nums.size() - 1]){
                begin = mid + 1;
            }else{
                break;
            }
            mid = int((end - begin) / 2) + begin;
        }
        return min(nums[mid], nums[begin]);
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    const int LEN = 6;
    int arr[LEN] = {4,5,6,1,2,3};
//    int arr[LEN] = {4,5,6, 7, 0 ,1, 2};
//    int arr[LEN] = {7,0};
    vector<int>nums(arr, arr + LEN);
    cout << s.findMin(nums) << endl;
    return 0;
}
