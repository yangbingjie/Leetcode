//
//  main.cpp
//  414_thirdMax
//
//  Created by Bella Yang on 2019/11/27.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int one = 0xFFC00000;
        int two = 0xFFC00000;
        int three = 0xFFC00000;
        for(int i = 0; i < nums.size(); ++i){
            if (nums[i] == one || nums[i] == two || nums[i] == three) {
                continue;
            }
            if(one == 0xFFC00000 || nums[i] > one){
                three = two;
                two = one;
                one = nums[i];
            }else if (two == 0xFFC00000 || nums[i] > two){
                three = two;
                two = nums[i];
            }else if (three == 0xFFC00000 || nums[i] > three){
                three = nums[i];
            }
        }
        return (three != 0xFFC00000) ? three : one;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    const int LEN = 3;
//    int array[LEN] = {1,2,2,5,3,5};
    int array[LEN] = {1,2,-2147483648};
//    int array[LEN] = {2,2,3,1};
    vector<int>vec(array ,array + LEN);
    cout << s.thirdMax(vec) << endl;
    return 0;
}
