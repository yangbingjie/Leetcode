//
//  main.cpp
//  154_findMin
//
//  Created by bella on 2020/7/22.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int begin = 0;
        int end = nums.size() - 1;
        int mid = int((end - begin) / 2) + begin;
        while (begin < end) {
            if (nums[mid] < nums[end]) {
                end = mid;
            }else if (nums[mid] > nums[end]){
                begin = mid + 1;
            }else{
                end--;
            }
            mid = int((end - begin) / 2) + begin;
        }
        return nums[begin];
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    const int LEN = 4;
    int arr[LEN] = {3,3,1,3};
    vector<int>nums(arr, arr + LEN);
    cout << s.findMin(nums) << endl;
    return 0;
}
