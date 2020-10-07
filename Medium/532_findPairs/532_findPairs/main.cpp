//
//  main.cpp
//  532_findPairs
//
//  Created by Bella Yang on 2020/10/7.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (nums.empty()) {
            return 0;
        }
        int count = 0;
        sort(nums.begin(), nums.end());
        if (k == 0) {
            int last_index = 0;
            int i = 1;
            while (i < nums.size()) {
                if (nums[i] != nums[i - 1]) {
                    if (i - last_index > 1) {
                        count++;
                    }
                    last_index = i;
                }
                ++i;
            }
            if (i - last_index > 1) {
                count++;
            }
            return count;
        }
        auto iter = unique(nums.begin(), nums.end());
        int n = int(iter - nums.begin());
        for (int slow = 0, fast = 1; fast < n;) {
            if (nums[fast] - nums[slow] == k) {
                count++;
                fast++;
                slow++;
            }else if (nums[fast] - nums[slow] < k){
                fast++;
            }else{
                slow++;
                fast = slow + 1;
            }
        }
        return count;
    }
};
int main(int argc, const char * argv[]) {
//    vector<int>nums={3, 1, 4, 1, 5};
    vector<int>nums={6,2,9,3,9,6,7,7,6,4};
    Solution s;
    cout << s.findPairs(nums, 3) << endl;
    return 0;
}
