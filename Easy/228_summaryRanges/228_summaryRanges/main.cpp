//
//  main.cpp
//  228_summaryRanges
//
//  Created by Bella Yang on 2021/1/10.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if (nums.empty()) {
            return result;
        }
        int start = 0;
        int end = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (long(nums[i]) - long(nums[i - 1]) == 1) {
                end++;
            }else{
                if (start == end) {
                    result.push_back(to_string(nums[start]));
                }else{
                    result.push_back(to_string(nums[start]) + "->" + to_string(nums[end]));
                }
                end++;
                start = end;
            }
        }
        if (start == end) {
            result.push_back(to_string(nums[start]));
        }else{
            result.push_back(to_string(nums[start]) + "->" + to_string(nums[end]));
        }
        return result;
    }
};
int main(int argc, const char * argv[]) {
    vector<int> nums = {0};
    Solution s;
    s.summaryRanges(nums);
    return 0;
}
