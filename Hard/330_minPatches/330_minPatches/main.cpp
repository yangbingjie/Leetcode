//
//  main.cpp
//  330_minPatches
//
//  Created by Bella Yang on 2020/12/29.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int patch = 0;
        int i = 0;
        if (nums.empty() ||  nums[i] != 1){
            patch++;
        }else{
            i++;
        }
        long max = 1;
        while (max < n) {
            if (i < nums.size() && nums[i] <= max + 1) {
                max += nums[i];
                i++;
            }else{
                patch++;
                max += max + 1;
            }
        }
        return patch;
    }
};
int main(int argc, const char * argv[]) {
    vector<int> nums = {1,2,31,33};
    Solution s;
    cout << s.minPatches(nums, 2147483647) << endl;
    return 0;
}
