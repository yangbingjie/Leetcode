//
//  main.cpp
//  1437_kLengthApart
//
//  Created by Bella Yang on 2020/10/7.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                n--;
            }else{
                if (n > 0) {
                    return false;
                }
                n = k;
            }
        }
        return true;
    }
};
int main(int argc, const char * argv[]) {
    vector<int>nums = {1,0,0,1,0,1};
    Solution s;
    cout << s.kLengthApart(nums, 2) << endl;
    return 0;
}
