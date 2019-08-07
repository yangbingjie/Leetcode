//
//  main.cpp
//  15_threeSum
//
//  Created by Bella Yang on 2019/8/6.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
//#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

class Solution {
public:
    static bool compare(int i, int j){
        if (i == 0 || abs(i) < abs(j) || (abs(i) == abs(j) && (i < 0 && j > 0))) {
            return true;
        }
        return false;
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() < 3) {
            return result;
        }
        sort(nums.begin(), nums.end(), this->compare);
        bool has_zero = false;
        if (nums[0] == 0) {
            has_zero = true;
        }
        int index = 0;
        int a;
        int b;
        while (nums[index] == 0) {
            index++;
        }
        a = index;
        b = index + 1;
        for (; a <= nums.size() - index - 1; ++a) {
            for (; b <= nums.size() - index; ++b) {
                if (has_zero &&nums[b] == -nums[a]) {
                    vector<int> tmp;
                    tmp.push_back(nums[a]);
                    tmp.push_back(nums[b]);
                    tmp.push_back(0);
                    result.push_back(tmp);
                    break;
                }
                if (find(nums.begin() + a, nums.end(), -(nums[a] + nums[b])) != nums.end()) {
                    vector<int> tmp;
                    tmp.push_back(nums[a]);
                    tmp.push_back(nums[b]);
                    tmp.push_back(-(nums[a] + nums[b]));
                    result.push_back(tmp);
                }
            }
        }
        
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    const int LEN = 6;
    int array[LEN] = {-1, 0, 1, 2, -1, -4};
    vector<int> nums(array, array + LEN);
    vector<vector<int>> result = s.threeSum(nums);
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[0].size(); ++j) {
            cout << result[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
