//
//  main.cpp
//  15_threeSum
//
//  Created by Bella Yang on 2019/8/6.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

class Solution {
public:
    
    
    //    Runtime: 120 ms, faster than 31.49% of C++ online submissions for 3Sum.
    //    Memory Usage: 18.5 MB, less than 19.81% of C++ online submissions for 3Sum.
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() < 3) {
            return result;
        }
        sort(nums.begin(), nums.end());
        bool has_zero = false;
        int zero_index_left = 0;
        int zero_index_right = 0;
        
        // 设置0的哨兵位
        for (int i = 0 ; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                if (!has_zero) {
                    has_zero = true;
                    zero_index_left = i;
                }
                zero_index_right = i;
            }
            if (!has_zero && nums[i] > 0) {
                zero_index_left = i;
                zero_index_right = i - 1;
                break;
            }
        }
        
        // 含有1一个0的三元组
        if (has_zero && zero_index_left - 1 >= 0 && zero_index_right + 1 < nums.size()) {
            for (int i = zero_index_left - 1, j = zero_index_right + 1; i >= 0 && j < nums.size();) {
                if (nums[i] == -nums[j] && (result.empty() || result[result.size() - 1][0] != nums[i])) {
                    vector<int> tmp;
                    tmp.push_back(nums[i]);
                    tmp.push_back(0);
                    tmp.push_back(nums[j]);
                    result.push_back(tmp);
                    i--;
                    j++;
                }else{
                    if (-nums[i] > nums[j]) {
                        j++;
                    }else{
                        i--;
                    }
                }
            }
        }
        
        // 含有三个0的三元组
        if (zero_index_right - zero_index_left >= 2) {
            vector<int> tmp;
            tmp.push_back(0);
            tmp.push_back(0);
            tmp.push_back(0);
            result.push_back(tmp);
        }
        
        int sum;
        
        // 两个负数，一个正数
        if (zero_index_right + 1 < nums.size() && zero_index_left> 1) {
            for (int k = zero_index_right + 1; k < nums.size(); ++k) {
                if (k > 0 && nums[k] == nums[k - 1]) {
                    continue;
                }
                for (int i = 0, j = zero_index_left - 1; j - i >= 1;) {
                    sum = -(nums[i] + nums[j]);
                    if (sum == nums[k] && (result.empty() || result[result.size() - 1][1] == 0 || result[result.size() - 1][2] != nums[k] || result[result.size() - 1][0] != nums[i])) {
                        vector<int> tmp;
                        tmp.push_back(nums[i]);
                        tmp.push_back(nums[j]);
                        tmp.push_back(sum);
                        result.push_back(tmp);
                        i++;
                        j--;
                    }else{
                        if (sum > nums[k]) {
                            i++;
                        }else{
                            j--;
                        }
                    }
                }
            }
        }
        
        // 两个正数，一个负数
        if (zero_index_right + 2 < nums.size() && zero_index_left> 0) {
            for (int k = 0; k < zero_index_left; ++k) {
                if (k > 0 && nums[k] == nums[k - 1]) {
                    continue;
                }
                for (int i = zero_index_right + 1, j = int(nums.size() - 1); j - i >= 1;) {
                    sum = -(nums[i] + nums[j]);
                    if (sum == nums[k] && (result.empty() || result[result.size() - 1][1] == 0 || result[result.size() - 1][0] != nums[k] || result[result.size() - 1][1] != nums[i])) {
                        vector<int> tmp;
                        tmp.push_back(sum);
                        tmp.push_back(nums[i]);
                        tmp.push_back(nums[j]);
                        result.push_back(tmp);
                        i++;
                        j--;
                    }else{
                        if (sum > nums[k]) {
                            i++;
                        }else{
                            j--;
                        }
                    }
                }
            }
        }
       
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    const int LEN = 16;
    int array[LEN] = {-4,-2,1,-5,-4,-4,4,-2,0,4,0,-2,3,1,-5,0};
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
