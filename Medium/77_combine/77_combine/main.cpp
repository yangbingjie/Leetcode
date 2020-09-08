//
//  main.cpp
//  77_combine
//
//  Created by bella on 2020/9/8.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
private:
    vector<vector<int>> result;
    vector<int> tmp;
public:
    void dfs(int start, int n, int k, vector<bool>& is_used){
        if (tmp.size() == k) {
            result.push_back(tmp);
            return;
        }
        for (int i = start; i < n ; ++i) {
            if (!is_used[i]) {
                is_used[i] = true;
                tmp.push_back(i + 1);
                dfs(i + 1, n, k, is_used);
                tmp.pop_back();
                is_used[i] = false;
            }
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<bool> is_used(n, false);
        dfs(0, n, k, is_used);
        return result;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    s.combine(4, 2);
    return 0;
}
