//
//  main.cpp
//  174_calculateMinimumHP
//
//  Created by bella on 2020/7/12.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int M = int(dungeon.size());
        int N = int(dungeon[0].size());
        vector<vector<int>>dp(M, vector<int>(N));
        dp[M - 1][N - 1] = 1;
        for (int i = M - 2; i >= 0; --i) {
            dp[i][N - 1] = max(dp[i + 1][N - 1] - dungeon[i + 1][N - 1], 1);
        }
        for (int j = N - 2; j >= 0; --j) {
            dp[M - 1][j] = max(dp[M - 1][j + 1] - dungeon[M - 1][j + 1], 1);
        }
        for (int i = M - 2; i >= 0; --i) {
            for (int j = N - 2; j >= 0; --j) {
                int right = max(1, dp[i][j + 1] - dungeon[i][j + 1]);
                int down = max(1, dp[i + 1][j] - dungeon[i + 1][j]);
                dp[i][j] = min(right, down);
            }
        }
        return max(dp[0][0] - dungeon[0][0], 1);
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    const int LEN1 = 3;
    const int LEN2 = 3;
//    int array[LEN1][LEN2] = {{0, -3}};
//    int array[LEN1][LEN2] = {{1,-3,3},{0,-2,0},{-3,-3,-3}};
    int array[LEN1][LEN2] = {{-2,-3,3},{-5,-10,1},{10,30,-5}};
    vector<vector<int>>dungeon;
    for (int i = 0; i < LEN1; ++i) {
        dungeon.push_back(vector<int>(array[i], array[i] + LEN2));
    }
    cout << s.calculateMinimumHP(dungeon) << endl;
    return 0;
}
