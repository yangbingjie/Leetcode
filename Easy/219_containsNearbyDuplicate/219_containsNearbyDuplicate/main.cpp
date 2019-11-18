//
//  main.cpp
//  219_containsNearbyDuplicate
//
//  Created by Bella Yang on 2019/11/18.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <iterator>
using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> m;
        map<int, int>::iterator iter;
        for (int i = 0; i < nums.size(); ++i) {
            iter = m.find(nums[i]);
            if (iter != m.end() && i - iter->second <= k) {
                return true;
            }
            m[nums[i]] = i;
        }
        return false;
    }
};
int main(int argc, const char * argv[]) {
    const int LEN = 6;
    int array[LEN] = {1,2,3,1,2,3};
    vector<int> vec(array, array + LEN);
    Solution s;
    cout << s.containsNearbyDuplicate(vec, 2);
    return 0;
}
