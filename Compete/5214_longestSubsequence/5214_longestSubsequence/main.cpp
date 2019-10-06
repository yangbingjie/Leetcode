//
//  main.cpp
//  5214_longestSubsequence
//
//  Created by Bella Yang on 2019/10/6.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        vector<int> nums(20001,0);
        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] - difference < -10000 || arr[i] - difference > 10000) {
                nums[arr[i]+ 10000] = 1;
            }else{
                nums[arr[i]+ 10000] = nums[arr[i]+ 10000 - difference] + 1;
            }
        }
        return *max_element(nums.begin(), nums.end());;
    }
};
int main(int argc, const char * argv[]) {
    const int LEN = 9;
    int array[LEN] = {1,5,7,8,5,3,4,2,1};
    vector<int> arr(array, array + LEN);
    Solution s;
    cout << s.longestSubsequence(arr, -2) << endl;
    return 0;
}
