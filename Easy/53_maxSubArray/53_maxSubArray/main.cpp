//
//  main.cpp
//  53_maxSubArray
//
//  Created by Bella Yang on 2019/9/11.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int max_value = nums[0];
        int i = 0;
        for (; i < nums.size(); ++i) {
            if (max_value < nums[i]) {
                max_value = nums[i];
            }
        }
        
        if (max_value <= 0) {
            return max_value;
        }
        
        int left_result = max_value;
        i = 0;
        while (i < nums.size() && nums[i] <= 0) {
            i++;
        }
        int buffer = 0;
        int a = nums[i];
        if(i == nums.size() - 1)
            return a;
        for (i++; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                if (a + buffer < 0) {
                    if (a > left_result) {
                        left_result = a;
                    }
                    a = nums[i];
                }else{
                    a = a + buffer + nums[i];
                    if (a > left_result) {
                        left_result = a;
                    }
                }
                buffer = 0;
            }else{
                buffer += nums[i];
            }
        }
        
        int right_result = max_value;
        i = int(nums.size() - 1);
        while (i >= 0 && nums[i] <= 0) {
            i--;
        }
        buffer = 0;
        a = nums[i];
        if(i == 0)
            return a;

        for (i--; i >= 0; --i) {
            if (nums[i] > 0) {
                if (a + buffer < 0) {
                    if (a > left_result) {
                        left_result = a;
                    }
                    a = nums[i];
                }else{
                    a = a + buffer + nums[i];
                    if (a > left_result) {
                        left_result = a;
                    }
                }
                buffer = 0;
            }else{
                buffer += nums[i];
            }
        }
        
        
        return max(left_result, right_result);
    }
};

int main(int argc, const char * argv[]) {
    const int LEN = 2;
//    int array[LEN] = {-2,1,-3,4,-1,2,1,-5,4};
    int array[LEN] = {1, 2};
    vector<int>nums(array, array + LEN);
    Solution s;
    cout << s.maxSubArray(nums) << endl;
    return 0;
}
