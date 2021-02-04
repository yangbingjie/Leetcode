//
//  main.cpp
//  643_findMaxAverage
//
//  Created by Bella Yang on 2021/2/4.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int slow = 0;
        int fast = k;
        int sum = 0;
        for (int i = 0; i < fast; ++i) {
            sum += nums[i];
        }
        int max_sum = sum;
        while (fast < nums.size()) {
            sum -= nums[slow];
            sum += nums[fast];
            max_sum = max(max_sum, sum);
            slow++;
            fast++;
        }
        return double(max_sum) / double(k);
    }
};
int main(int argc, const char * argv[]) {
    vector<int>nums = {1,12,-5,-6,50,3};
    Solution s;
    cout << s.findMaxAverage(nums, 4) << endl;
    return 0;
}
