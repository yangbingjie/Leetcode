//
//  main.cpp
//  560_subarraySum
//
//  Created by Bella Yang on 2020/5/15.
//  Copyright © 2020 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <iterator>
#include <map>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int>m;
        m[0] = 1;
        int count = 0;
        int pre_sum = 0;
        map<int, int>::iterator iter;
        for (int i = 1; i < nums.size() + 1; ++i) {
            pre_sum += nums[i - 1];
            iter = m.find(pre_sum - k);
            if (m.end() != iter) {
                count += iter->second;
            }
            if (m.end() != m.find(pre_sum)) {
                m[pre_sum]++;
            }else{
                m[pre_sum] = 1;
            }
        }
        return count;
    }
};
int main(int argc, const char * argv[]) {
    const int LEN = 3;
    int arr[LEN] = {1,1,1};
    vector<int>nums(arr, arr + LEN);
    Solution s;
    cout << s.subarraySum(nums, 2) << endl;
    return 0;
}
