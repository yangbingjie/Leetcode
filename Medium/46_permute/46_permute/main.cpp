//
//  main.cpp
//  46_permute
//
//  Created by Bella Yang on 2019/9/7.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void insert(vector<vector<int>>& result, int target, int length){
        vector<int>tmp;
        for (int k = 0; k < length; ++k) {
            for (int m = 0; m < result[0].size(); ++m) {
                tmp.insert(tmp.end(), result[k].begin(), result[k].begin() + m);
                tmp.push_back(target);
                tmp.insert(tmp.end(), result[k].begin() + m, result[k].end());
                result.push_back(tmp);
                tmp.clear();

            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.empty()) {
            return result;
        }
        result.push_back(vector<int>(nums.begin(), nums.begin() + 1));
        int length;
        for (int i = 1; i < nums.size(); ++i) {
            length = int(result.size());
            insert(result, nums[i], length);
            for (int j = 0; j < length; ++j) {
                result[j].push_back(nums[i]);
            }
        }
        return result;
    }
};
int main(int argc, const char * argv[]) {
    const int LEN = 4;
    int array[LEN] = {5, 4 ,6, 2};
    vector<int> nums(array, array + LEN);
    Solution s;
    s.permute(nums);
    return 0;
}
