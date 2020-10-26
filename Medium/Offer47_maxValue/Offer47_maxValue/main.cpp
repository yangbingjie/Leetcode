//
//  main.cpp
//  Offer47_maxValue
//
//  Created by Bella Yang on 2020/10/26.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        for (int i = 1; i < grid.size(); ++i) {
            grid[i][0] += grid[i - 1][0];
        }
        for (int j = 1; j < grid[0].size(); ++j) {
            grid[0][j] += grid[0][j - 1];
        }
        for (int i = 1; i < grid.size(); ++i) {
            for (int j = 1; j < grid[0].size(); ++j) {
                grid[i][j] += max(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        return grid[grid.size() - 1][grid[0].size() - 1];
    }
};
int main(int argc, const char * argv[]) {
    vector<vector<int>> grid ={
        {1,3,1},
        {1,5,1},
        {4,2,1}};
    Solution s;
    cout << s.maxValue(grid) << endl;
    return 0;
}
