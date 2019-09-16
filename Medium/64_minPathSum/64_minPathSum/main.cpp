//
//  main.cpp
//  64_minPathSum
//
//  Created by Bella Yang on 2019/9/16.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int recurPathSum(vector<vector<bool>>& visited, vector<vector<int>>& grid, int i, int j){
        if (!visited[i][j]) {
            visited[i][j] = true;
            if (i == 0 && j == 0) {
                return grid[i][j];
            }
            if (i == 0) {
                grid[i][j] += recurPathSum(visited, grid, i, j - 1);
                return grid[i][j];
            }
            if (j == 0) {
                grid[i][j] += recurPathSum(visited, grid, i - 1, j);
                return grid[i][j];
            }
            grid[i][j] += min(recurPathSum(visited, grid, i - 1, j), recurPathSum(visited, grid, i, j - 1));
        }
        return grid[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty()) {
            return 0;
        }
        vector<vector<bool>> visited(int(grid.size()), vector<bool>(int(grid[0].size()), false));
        return recurPathSum(visited, grid, int(grid.size()) - 1, int(grid[0].size()) - 1);
    }
};
int main(int argc, const char * argv[]) {
    const int M = 3;
    const int N = 3;
    int array[M][N] = {
        {1,3,1},
        {1,5,1},
        {4,2,1}
    };
    vector<vector<int>> grid;
    for (int i = 0; i < M; ++i) {
        grid.push_back(vector<int>(array[i], array[i] + N));
    }
    Solution s;
    cout << s.minPathSum(grid) << endl;
    return 0;
}
