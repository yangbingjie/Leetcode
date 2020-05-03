//
//  main.cpp
//  78_subsets
//
//  Created by Bella Yang on 2020/5/3.
//  Copyright © 2020 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> vec;
        vector<int> v;
        vec.push_back(v);
        int end = 1;
        for(int i = 0; i < nums.size(); ++i){
            vector<int> tmp;
            tmp.push_back(nums[i]);
            vec.push_back(tmp);
            for(int j = 1; j < end; ++j){
                vector<int> tmp(vec[j]);
                tmp.push_back(nums[i]);
                vec.push_back(tmp);
            }
            end = vec.size();
        }
        return vec;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    const int LEN = 3;
    int array[LEN] = {1,2,3};
    vector<int>nums(array, array + LEN);
    s.subsets(nums);
    return 0;
}
