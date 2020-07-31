//
//  main.cpp
//  08.03_findMagicIndex
//
//  Created by bella on 2020/7/31.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int recurFindMagic(vector<int>& nums, int begin, int end){
        if (begin >= end) {
            return -1;
        }
        int ind;
        int mid = begin + (end - begin) / 2;
        if (nums[mid] == mid){
            ind = recurFindMagic(nums, begin, mid);
            return ind != -1 ? ind : mid;
        }else{
            ind = recurFindMagic(nums, begin, mid);
            if (ind == -1) {
                ind = recurFindMagic(nums, mid + 1, end);
            }
            return ind;
        }
    }
    int findMagicIndex(vector<int>& nums) {
        return recurFindMagic(nums, 0, nums.size());
    }
};
int main(int argc, const char * argv[]) {
    const int LEN = 38;
    int arr[LEN] = {-531369933, -469065528, -430059048, -428981853, -319235969, -288076332, -286667432, -282312559, -197049680, -197022263, -174416117, -138027773, -121899023, -111631966, -107567458, -70437707, -52463072, -45519851, -38641451, -15825815, -3835472, -1525043, 22, 566842886, 593757472, 605439236, 619794079, 640069993, 657657758, 718772950, 815849552, 839357142, 936585256, 1006188278, 1042347147, 1057129320, 1062178586, 1069769438};
    vector<int>nums(arr, arr + LEN);
    Solution s;
    cout << s.findMagicIndex(nums) << endl;
    return 0;
}
