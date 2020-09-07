//
//  main.cpp
//  347_topKFrequent
//
//  Created by bella on 2020/9/7.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
class Solution {
public:
    static bool cmp(pair<int, int>& p1, pair<int, int>& p2){
        return p1.second > p2.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>m;
        for (int i = 0; i < nums.size(); ++i) {
            m[nums[i]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)>q(cmp);
        auto iter = m.begin();
        for (int i = 0; iter != m.end(); ++i, iter++) {
            if (q.size() == k) {
                if (q.top().second < (iter->second)) {
                    q.pop();
                    q.emplace(iter->first, iter->second);
                }
            }else{
                q.emplace(iter->first, iter->second);
            }
        }
        vector<int> vec;
        while (!q.empty()) {
            vec.push_back(q.top().first);
            q.pop();
        }
        return vec;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    vector<int>nums = {1,1,1,2,2,3};
    s.topKFrequent(nums, 2);
    return 0;
}
