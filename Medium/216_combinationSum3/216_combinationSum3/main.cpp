//
//  main.cpp
//  216_combinationSum3
//
//  Created by bella on 2020/8/11.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
private:
    vector<vector<int>>result;
    vector<int> tmp;
public:
    void recur(int k, int n, int min_num){
        if (k == 1) {
            if (n >= 1 && n <= 9 && n >= min_num) {
                tmp.push_back(n);
                result.push_back(tmp);
                tmp.pop_back();
            }
            return;
        }
        for (int i = min_num; i < n && i <= 9; ++i) {
            tmp.push_back(i);
            recur(k - 1, n - i, i + 1);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        recur(k, n, 1);
        return result;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    s.combinationSum3(3, 9);
    return 0;
}
