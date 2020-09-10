//
//  main.cpp
//  40_combinationSum2
//
//  Created by bella on 2020/9/10.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution {
private:
    vector<vector<int>>result;
    vector<int>tmp;
    set<vector<int>>s;
public:
    void dfs(int start, vector<int> & candidates, int target){
        if (target == 0) {
            auto iter = s.find(tmp);
            if (iter == s.end()) {
                result.push_back(tmp);
                s.insert(tmp);
            }
            return;
        }
        for (int i = start; i < candidates.size(); ++i) {
            if (target >= candidates[i]) {
                tmp.push_back(candidates[i]);
                dfs(i + 1, candidates, target - candidates[i]);
                tmp.pop_back();
            }else{
                break;
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(0, candidates, target);
        return result;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    vector<int>vec = {10,1,2,7,6,1,5};
    s.combinationSum2(vec, 8);
    return 0;
}
