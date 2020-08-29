//
//  main.cpp
//  17.10_majorityElement
//
//  Created by bella on 2020/8/28.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int result = 0;
        int one_count;
        for(int i = 0; i < 32; ++i){
            one_count = 0;
            for(int j = 0; j < nums.size(); ++j){
                one_count += (nums[j] >> (32 - i - 1)) & 1;
            }
            if(one_count > nums.size() / 2){
                result |= (1 << (32 - i - 1));
            }
        }
        return result;
    }
};
int main(int argc, const char * argv[]) {
    const int LEN = 9;
    int arr[LEN] = {1,2,5,9,5,9,5,5,5};
    vector<int>vec(arr, arr + LEN);
    Solution s;
    cout << s.majorityElement(vec) << endl;
    return 0;
}
