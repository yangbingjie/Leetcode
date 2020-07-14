//
//  main.cpp
//  594_findLHS
//
//  Created by bella on 2020/7/14.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    int findLHS(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        map<int, int>m;
        map<int, int>::iterator iter;
        for (int i = 0; i < nums.size(); ++i) {
            iter = m.find(nums[i]);
            if (iter != m.end()) {
                iter->second++;
            }else{
                m[nums[i]] = 1;
            }
        }
        int lhs = 0;
        iter = m.begin();
        map<int, int>::iterator fast = m.begin();
        fast++;
        while (fast != m.end()) {
            if (fast->first - iter->first == 1) {
                lhs = max(lhs, iter->second + fast->second);
            }
            iter++;
            fast++;
        }
        return lhs;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    const int LEN = 8;
    int arr[LEN] = {1,3,2,2,5,2,3,7};
    vector<int>nums(arr, arr + LEN);
    cout << s.findLHS(nums) << endl;
    return 0;
}
