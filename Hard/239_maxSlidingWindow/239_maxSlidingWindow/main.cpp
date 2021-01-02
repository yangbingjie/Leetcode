//
//  main.cpp
//  239_maxSlidingWindow
//
//  Created by Bella Yang on 2021/1/2.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k == 1) {
            return nums;
        }
        priority_queue<pair<int, int>> que;
        int max_val = nums[0];
        for (int i = 0; i < k; ++i) {
            max_val = max(max_val, nums[i]);
            que.push(pair<int, int>(nums[i], i));
        }
        vector<int>result = {max_val};
        for (int i = k; i < nums.size(); ++i) {
            que.push(pair<int, int>(nums[i], i));
            while (que.top().second <= i - k) {
                que.pop();
            }
            result.push_back(que.top().first);
        }
        return result;
    }
};
int main(int argc, const char * argv[]) {
    vector<int> vec = {1,3,-1,-3,-2,3,6,7};
    Solution s;
    s.maxSlidingWindow(vec, 3);
    return 0;
}
