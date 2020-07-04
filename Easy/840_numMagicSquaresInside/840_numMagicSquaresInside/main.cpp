//
//  main.cpp
//  840_numMagicSquaresInside
//
//  Created by bella on 2020/7/4.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool check(vector<vector<int>>&grid, int i, int j){
        if (grid[i + 1][j + 1] != 5) {
            return false;
        }
        int is_appear = 0;
        int tmp = 1;
        for (int a = i; a < i + 3; ++a) {
            for (int b = j; b < j + 3; ++b) {
                if (grid[a][b] > 9 || grid[a][b] < 1) {
                    return false;
                }
                if ((is_appear & (tmp << (grid[a][b] - 1))) == 0) {
                    is_appear = is_appear | (tmp << ((grid[a][b]) - 1));
                }else{
                    return false;;
                }
            }
        }
        if (is_appear != 511) {
            return false;
        }
        return grid[i][j] + grid[i][j + 1] + grid[i][j + 2] == 15
        && grid[i + 1][j] + grid[i + 1][j + 1] + grid[i + 1][j + 2] == 15
        && grid[i + 2][j] + grid[i + 2][j + 1] + grid[i + 2][j + 2] == 15
        && grid[i][j] + grid[i + 1][j] + grid[i + 2][j] == 15
        && grid[i][j + 1] + grid[i + 1][j + 1] + grid[i + 2][j + 1] == 15
        && grid[i][j + 2] + grid[i + 1][j + 2] + grid[i + 2][j + 2] == 15
        && grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2] == 15
        && grid[i][j + 2] + grid[i + 1][j + 1] + grid[i + 2][j] == 15;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        if (grid.size() < 3 || grid[0].size() < 3) {
            return 0;
        }
        int num = 0;
        for (int i = 0; i < grid.size() - 2; ++i) {
            for (int j = 0; j < grid[0].size() - 2; ++j) {
                if (check(grid, i, j)) {
                    num++;
                }
            }
        }
        return num;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    const int LEN1 = 3;
    const int LEN2 = 4;
//    int arr[LEN1][LEN2] = {{4,3,8,4},{9,5,1,9},{2,7,6,2}};
    int arr[LEN1][LEN2] = {{5,5,5,4},{5,5,5,9},{5,5,5,2}};
    vector<vector<int>>grid;
    for (int i = 0; i < LEN1; ++i) {
        grid.push_back(vector<int>(arr[i], arr[i] + LEN2));
    }
    cout << s.numMagicSquaresInside(grid) << endl;
    return 0;
}
