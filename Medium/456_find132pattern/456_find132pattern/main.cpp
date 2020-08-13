//
//  main.cpp
//  456_find132pattern
//
//  Created by bella on 2020/8/12.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if (nums.size() < 3) {
            return false;
        }
        vector<int>pre_min(nums.size());
        pre_min[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            pre_min[i] = min(pre_min[i - 1], nums[i]);
        }
        stack<int>sta;
        sta.push(nums[nums.size() - 1]);
        for (int i = nums.size() - 2; i >= 0; --i) {
            if (nums[i] > pre_min[i]) {
                while (!sta.empty() && sta.top() <= pre_min[i]) {
                    sta.pop();
                }
                if (!sta.empty() && sta.top() < nums[i]) {
                    return true;
                }
                sta.push(nums[i]);
            }
        }
        return false;
    }
};
int main(int argc, const char * argv[]) {
    const int LEN = 4;
    int arr[LEN] = {3, 1, 4, 2};
    vector<int>vec(arr, arr + LEN);
    Solution s;
    cout << s.find132pattern(vec) << endl;
    return 0;
}
