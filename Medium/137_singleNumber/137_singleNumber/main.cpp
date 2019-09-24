//
//  main.cpp
//  137_singleNumber
//
//  Created by Bella Yang on 2019/9/24.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int M = 0;
        int N = 0;
        for (int k = 0; k < nums.size(); ++k) {
            M = (~N) & (M ^ nums[k]);
            N = (~M) & (N ^ nums[k]);
        }
        return M;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    const int LEN = 7;
    int array[LEN] = {0,1,0,1,0,1,99};
    vector<int> nums(array, array + LEN);
    cout << s.singleNumber(nums) << endl;
    return 0;
}
