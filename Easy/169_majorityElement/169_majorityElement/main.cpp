//
//  main.cpp
//  169_majorityElement
//
//  Created by Bella Yang on 2019/10/21.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <iterator>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};

int main(int argc, const char * argv[]) {
    const int LEN = 5;
    int array[LEN] = {2,2,1,1,2};
    Solution s;
    vector<int>nums(array, array + LEN);
    cout << s.majorityElement(nums) << endl;
    return 0;
}
