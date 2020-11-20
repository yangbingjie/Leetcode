//
//  main.cpp
//  695_maxAreaOfIsland
//
//  Created by Bella Yang on 2020/11/20.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
private:
    static const int LEN = 4;
    int diff_x[LEN] = {0,0,1,-1};
    int diff_y[LEN] = {1,-1,0,0};
    int area;
public:
    void dfs(vector<vector<int>>& grid, int x, int y){
        int xx, yy;
        for (int i = 0; i < LEN; ++i) {
            xx = x + diff_x[i];
            yy = y + diff_y[i];
            if (xx >= 0 && yy >=0 && xx < grid.size() && yy < grid[0].size() && grid[xx][yy] == 1) {
                grid[xx][yy] = -1;
                area++;
                dfs(grid, xx, yy);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    area = 1;
                    grid[i][j] = -1;
                    dfs(grid, i, j);
                    max_area = max(area, max_area);
                }
            }
        }
        return max_area;
    }
};
int main(int argc, const char * argv[]) {
    vector<vector<int>>grid = {
        {0,0,1,0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,1,1,0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,1,1,0,0,1,0,1,0,0},
        {0,1,0,0,1,1,0,0,1,1,1,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,1,1,0,0,0,0}};
    Solution s;
    cout << s.maxAreaOfIsland(grid) <<endl;

    return 0;
}
