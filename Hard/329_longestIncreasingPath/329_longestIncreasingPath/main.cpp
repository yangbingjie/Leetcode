//
//  main.cpp
//  329_longestIncreasingPath
//
//  Created by bella on 2020/7/26.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution {
private:
    int row;
    int col;
public:
    int dfs(vector<vector<int>>& matrix, int x, int y, vector<vector<int>>&dp){
        if (dp[x][y] != -1) {
            return dp[x][y];
        }
        if (x - 1 >= 0 && matrix[x][y] < matrix[x - 1][y]) {
            dp[x][y] = max(dp[x][y], dfs(matrix, x - 1, y, dp) + 1);
        }
        if (y - 1 >= 0 && matrix[x][y] < matrix[x][y - 1]) {
            dp[x][y] = max(dp[x][y], dfs(matrix, x, y - 1, dp) + 1);
        }
        if (x + 1 < row && matrix[x][y] < matrix[x + 1][y]) {
            dp[x][y] = max(dp[x][y], dfs(matrix, x + 1, y, dp) + 1);
        }
        if (y + 1 < col && matrix[x][y] < matrix[x][y + 1]) {
            dp[x][y] = max(dp[x][y], dfs(matrix, x, y + 1, dp) + 1);
        }
        dp[x][y] = max(1, dp[x][y]);
        return dp[x][y];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }
        this->row = matrix.size();
        this->col = matrix[0].size();
        int max_path = 0;
        vector<vector<int>>dp(this->row, vector<int>(this->col, -1));
        for (int i = 0; i < this->row; ++i) {
            for (int j = 0; j < this->col; ++j) {
               max_path = max(max_path, dfs(matrix, i, j, dp));
            }
        }
        return max_path;
    }
};
int main(int argc, const char * argv[]) {
    const int LEN1 = 3;
    const int LEN2 = 3;
//    int arr[LEN1][LEN2] = {{9,9,4},{6,6,8},{2,1,1}};
    int arr[LEN1][LEN2] = {{7,8,9},{9,7,6},{7,2,3}};
//    int arr[LEN1][LEN2] = {{3,4,5},{3,2,6},{2,2,1}};
    vector<vector<int>>vec(LEN1, vector<int>(LEN2));
    for (int i = 0; i < LEN1; ++i) {
        vec[i] = vector<int>(arr[i], arr[i] + LEN2);
    }
    Solution s;
    cout << s.longestIncreasingPath(vec) << endl;
    return 0;
}
