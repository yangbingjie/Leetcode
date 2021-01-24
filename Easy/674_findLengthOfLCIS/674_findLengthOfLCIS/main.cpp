//
//  main.cpp
//  674_findLengthOfLCIS
//
//  Created by Bella Yang on 2021/1/24.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int max_len = 1;
        int len = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) {
                len++;
                max_len = max(max_len, len);
            }else{
                len = 1;
            }
        }
        return max(max_len, len);
    }
};
int main(int argc, const char * argv[]) {
    vector<int> nums = {1,3,5,4,7};
    Solution s;
    cout << s.findLengthOfLCIS(nums) << endl;
    return 0;
}
