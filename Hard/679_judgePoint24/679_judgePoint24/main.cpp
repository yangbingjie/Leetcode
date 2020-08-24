//
//  main.cpp
//  679_judgePoint24
//
//  Created by bella on 2020/8/22.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <list>
using namespace std;

class Solution {
public:
    bool dfs(vector<double>& nums){
        if (nums.size() == 0) {
            return false;
        }
        if (nums.size() == 1) {
            return fabs(nums[0] - 24) < 1e-6;
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums.size(); ++j) {
                if (i == j) {
                    continue;
                }
                vector<double>others;
                for (int k = 0; k < nums.size(); ++k) {
                    if (k != i && k != j) {
                        others.push_back(nums[k]);
                    }
                }
                if (j > i) {
                    others.push_back(nums[i] + nums[j]);
                    if (dfs(others)) {
                        return true;
                    }
                    others.pop_back();
                    others.push_back(nums[i] * nums[j]);
                    if (dfs(others)) {
                        return true;
                    }
                    others.pop_back();
                }
                others.push_back(nums[i] - nums[j]);
                if (dfs(others)) {
                    return true;
                }
                others.pop_back();
                if (abs(nums[j]) > 1e-6) {
                    others.push_back(nums[i] / nums[j]);
                    if (dfs(others)) {
                        return true;
                    }
                    others.pop_back();
                }
            }
        }
        return false;
    }
    bool judgePoint24(vector<int>& nums) {
        vector<double> v(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            v[i] = (double) nums[i];
        }
        return dfs(v);
    }
};
int main(int argc, const char * argv[]) {
    const int LEN = 4;
    int arr[LEN] = {4,1,8,7};
    vector<int>nums(arr, arr + LEN);
    Solution s;
    cout << s.judgePoint24(nums) << endl;
    return 0;
}
