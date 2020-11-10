//
//  main.cpp
//  31_nextPermutation
//
//  Created by Bella Yang on 2020/11/10.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = -1;
        for (int n = nums.size() - 2; n >= 0; --n) {
            if (nums[n] < nums[n + 1]) {
                i = n;
                break;
            }
        }
        if (i != -1) {
            for (int m = nums.size() - 1 ; m >= i + 1; --m) {
                if (nums[i] < nums[m]) {
                    swap(nums[i], nums[m]);
                    break;
                }
            }
           
        }
        for (int n = i + 1, m = nums.size() - 1; n < m; ++n, --m) {
            swap(nums[n], nums[m]);
        }
    }
};
int main(int argc, const char * argv[]) {
    vector<int>nums = {1,3,2};
    Solution s;
    s.nextPermutation(nums);
    return 0;
}
