//
//  main.cpp
//  90_subsetsWithDup
//
//  Created by Bella Yang on 2020/5/4.
//  Copyright © 2020 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> vec;
        vector<int> v;
        vec.push_back(v);
        map<int, int> m;
        for(int i = 0; i < nums.size(); ++i){
            if(m.find(nums[i]) != m.end()){
                m[nums[i]]++;
            }else{
                m[nums[i]] = 1;
            }
        }
        map<int, int>::iterator iter = m.begin();
        int end = 1;
        while(iter != m.end()){
            for(int i = 1; i <= iter->second; ++i){
                vector<int>tmp(i, iter->first);
                vec.push_back(tmp);
                for(int j = 1; j < end; ++j){
                    vector<int>t(vec[j]);
                    t.insert(t.end(), tmp.begin(), tmp.end());
                    vec.push_back(t);
                }
            }
            end = vec.size();
            iter++;
        }
        return vec;
    }
};


int main(int argc, const char * argv[]) {
    Solution s;
    const int LEN = 3;
    int array[LEN] = {1,2,2};
    vector<int> nums(array, array + LEN);
    s.subsetsWithDup(nums);
    return 0;
}
