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
        int vote = 0;
        int result = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (vote == 0) {
                vote++;
                result = nums[i];
            }else{
                vote += (result == nums[i]) ? 1 : -1;
            }
        }
        return result;
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
