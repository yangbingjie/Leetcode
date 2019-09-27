//
//  main.cpp
//  217_containsDuplicate
//
//  Created by Bella Yang on 2019/9/27.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size() <= 1){
            return false;
        }
        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i - 1] == nums[i]){
                return true;
            }
        }
        return false;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    const int LEN = 4;
    int array[LEN] = {1, 2, 3, 4};
    vector<int> nums(array, array + LEN);
    cout << s.containsDuplicate(nums) << endl;
    return 0;
}
