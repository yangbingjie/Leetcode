//
//  main.cpp
//  665_checkPossibility
//
//  Created by Bella Yang on 2021/2/7.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool change = false;
        int ind = 0;
        int max_value = INT_MIN;
        int tmp;
        while(ind + 1 < nums.size()){
            if(nums[ind] > nums[ind + 1]){
                if(!change){
                    change = true;
                    tmp = ind > 0 ? max(nums[ind - 1], max_value) : max_value;
                    if (tmp <= nums[ind + 1]) {
                        nums[ind] = tmp;
                    }else{
                        nums[ind + 1] = nums[ind];
                    }
                    max_value = max(max_value, nums[ind]);
                    continue;
                }else{
                    return false;
                }
            }
            ind++;
            max_value = max(max_value, nums[ind - 1]);
        }
        return true;
    }
};
int main(int argc, const char * argv[]) {
    vector<int> nums = {4,2,1};
    Solution s;
    cout << s.checkPossibility(nums) << endl;
    return 0;
}
