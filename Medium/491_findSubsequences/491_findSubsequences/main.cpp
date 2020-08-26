//
//  main.cpp
//  491_findSubsequences
//
//  Created by bella on 2020/8/25.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    long calHash(vector<int>&vec, long max_value){
        long hash = 0;
        for (int i = 0; i < vec.size(); ++i) {
            hash = (hash + ((vec[i] + 101) + hash * max_value) % 99997871) % 99997871;
        }
        return hash;
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>>result;
        if (nums.empty()) {
            return result;
        }
        int n = nums.size();
        vector<int>patterns(1 << n);
        for(int i = 0; i < patterns.size(); ++i){
            patterns[i] = i;
        }
        set<long> hash_set;
        long hash;
        long max_value = *max_element(nums.begin(), nums.end()) + 1;
        int last_value;
        bool flag;
        for (int i = 0; i < patterns.size(); ++i) {
            vector<int>tmp;
            last_value = -101;
            flag = true;
            for (int j = 0; patterns[i] != 0; ++j) {
                if (patterns[i] % 2 == 1) {
                    if (last_value > nums[j]) {
                        flag = false;
                        break;
                    }
                    tmp.push_back(nums[j]);
                    last_value = nums[j];
                }
                patterns[i] >>= 1;
            }
            if (flag && tmp.size() >= 2) {
                hash = calHash(tmp, max_value);
                if (hash_set.find(hash) == hash_set.end()) {
                    result.push_back(tmp);
                    hash_set.insert(hash);
                }
            }
        }
        return result;
    }
};
int main(int argc, const char * argv[]) {
    const int LEN = 11;
    int arr [LEN] = {100,90,80,70,60,50,60,70,80,90,100};
    vector<int>vec(arr, arr + LEN);
    Solution s;
    s.findSubsequences(vec);
    return 0;
}
