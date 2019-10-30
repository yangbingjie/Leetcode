//
//  main.cpp
//  39_combinationSum
//
//  Created by Bella Yang on 2019/10/30.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
private:
    vector<vector<int>> result;
    vector<int> temp;
public:
    void combinationSum(vector<int>& candidates, int target, int start) {
        if (target <= 0) {
            if (target == 0) {
                this->result.push_back(this->temp);
            }
            return;
        }
        for (int i = start; i < candidates.size(); ++i) {
            temp.push_back(candidates[i]);
            combinationSum(candidates, target - candidates[i], i);
            this->temp.erase(temp.end() - 1);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        this->combinationSum(candidates, target, 0);
        return this->result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    const int LEN = 3;
    int array[LEN] = {2, 3, 5};
    vector<int>candidates(array, array + LEN);
    s.combinationSum(candidates, 8);
    return 0;
}
