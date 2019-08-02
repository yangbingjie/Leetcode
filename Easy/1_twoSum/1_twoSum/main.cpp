//
//  main.cpp
//  1_twoSum
//
//  Created by Bella Yang on 2019/8/1.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>
using namespace std;

// Normal
//class Solution {
//public:
//    vector<int> twoSum(vector<int>& nums, int target) {
//        vector<int>result;
//        for (int i = 0; i < nums.size(); ++i) {
//            for (int j = i + 1; j < nums.size(); ++j) {
//                if (nums[i] + nums[j] == target) {
//                    result.push_back(i);
//                    result.push_back(j);
//                    return result;
//                }
//            }
//        }
//        return result;
//    }
//};


// Using Muitimap
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>result;
        multimap<int, int>nums_map;
        for (int i = 0; i < nums.size(); ++i) {
            nums_map.insert(pair<int, int>(nums[i], i));
        }
        multimap<int, int>::iterator i = nums_map.begin();
        multimap<int, int>::iterator j = --nums_map.end();

        while (i != j) {
            int sum = i->first + j->first;
            if (sum == target) {
                if (i->second < j->second) {
                    result.push_back(i->second);
                    result.push_back(j->second);
                }else{
                    result.push_back(j->second);
                    result.push_back(i->second);
                }
                return result;
            }else if (sum < target){
                i++;
            }else{
                j--;
            }
        }
        return result;
    }
};




int main(int argc, const char * argv[]) {
    Solution s;
    const int len = 4;
    int array[len] = {11, 3, 1, 3};
    vector<int>nums(array, array + len);
    vector<int> result = s.twoSum(nums, 6);
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << ' ';
    }
    cout << endl;
    return 0;
}
