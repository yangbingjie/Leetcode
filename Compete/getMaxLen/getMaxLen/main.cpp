//
//  main.cpp
//  getMaxLen
//
//  Created by bella on 2020/8/30.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    int find_max_len(vector<int>& nums, int begin, int end){
        if (begin < 0 || end > nums.size() || begin >= end) {
            return 0;
        }
        int max_len = 0;
        vector<int>prefix(end - begin);
        prefix[0] = nums[begin] > 0 ? 1 : -1;
        for (int i = 1; begin + i < end; ++i) {
            prefix[i] = prefix[i - 1] * (nums[begin + i] > 0 ? 1 : -1);
        }
        if (prefix[prefix.size() - 1] > 0) {
            max_len = end - begin;
        }else{
            for (int i = end - begin - 2; i >= 0 ; --i) {
                if (prefix[i] > 0) {
                    return i + 1;
                }
                for (int j = i + 1; j < prefix.size(); ++j) {
                    if (prefix[j] / prefix[j - i - 1] > 0) {
                        return i + 1;
                    }
                }
            }
        }
        return max_len;
    }
    int getMaxLen(vector<int>& nums) {
        int i = 0;
        int last_ind = -1;
        int max_len = 0;
        while (i < nums.size()) {
            if (nums[i] == 0) {
                if (last_ind < i) {
                    max_len = max(max_len, find_max_len(nums, max(0, last_ind), i));
                }
                last_ind = i + 1;
            }
            ++i;
        }
        if (last_ind == -1 || last_ind < nums.size()) {
            max_len = max(max_len, find_max_len(nums, max(last_ind, 0), nums.size()));
        }
        return max_len;
    }
};
int main(int argc, const char * argv[]) {
    const int LEN = 20;
    int arr[LEN] = {5,-20,-20,-39,-5,0,0,0,36,-32,0,-7,-10,-7,21,20,-12,-34,26,2};
    vector<int>vec(arr, arr + LEN);
    Solution s;
    cout << s.getMaxLen(vec) << endl;
    return 0;
}
