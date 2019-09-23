//
//  main.cpp
//  136_singleNumber
//
//  Created by Bella Yang on 2019/9/23.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for(int i = 0; i < nums.size(); ++i){
            result ^= nums[i];
        }
        return result;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    const int LEN = 5;
    int array[LEN] = {4, 4, 3, 1};
    vector<int> nums(array, array + LEN);
    cout << s.singleNumber(nums);
    return 0;
}
