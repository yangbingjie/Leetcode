//
//  main.cpp
//  268_missingNumber
//
//  Created by Bella Yang on 2019/11/23.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int result = 0;
        for(int i = 0; i < nums.size(); ++i){
            result ^= nums[i];
            result ^= i;
        }
        result ^= nums.size();
        return result;
    }
};
int main(int argc, const char * argv[]) {
    const int LEN = 9;
    int array[LEN] = {9,6,4,2,3,5,7,0,1};
    vector<int>nums(array, array + LEN);
    Solution s;
    cout << s.missingNumber(nums) << endl;
    return 0;
}
