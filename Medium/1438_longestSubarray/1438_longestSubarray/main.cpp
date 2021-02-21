//
//  main.cpp
//  1438_longestSubarray
//
//  Created by Bella Yang on 2021/2/21.
//

#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>
using namespace std;
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int length = 1;
        int slow = 0;
        int fast = 1;
        map<int, int>m;
        m[nums[0]] = 1;
        auto iter = m.begin();
        while (fast < nums.size()) {
            while (!m.empty() && (abs(nums[fast] - m.begin()->first) > limit || abs(nums[fast] - m.rbegin()->first) > limit)) {
                iter = m.find(nums[slow]);
                --(iter->second);
                if (iter->second == 0) {
                    m.erase(iter);
                }
                slow++;
            }
            length = max(length, fast - slow + 1);
            iter = m.find(nums[fast]);
            if (iter != m.end()) {
                ++(iter->second);
            }else{
                m[nums[fast]] = 1;
            }
            fast++;
        }
        return length;
    }
};
int main(int argc, const char * argv[]) {
    vector<int> nums = {4,2,2,2,4,4,2,2};
    Solution s;
    cout << s.longestSubarray(nums, 0) << endl;
    return 0;
}
