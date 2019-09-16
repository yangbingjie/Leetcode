//
//  main.cpp
//  63_uniquePathsWithObstacles
//
//  Created by Bella Yang on 2019/9/16.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int recurPath(vector<vector<int>>& obstacleGrid, int i, int j){
        if (i == 0 || j == 0) {
            return obstacleGrid[i][j];
        }
        if (obstacleGrid[i][j] == -2) {
            return 0;
        }
        if (obstacleGrid[i][j] == -1) {
            int a = recurPath(obstacleGrid, i - 1, j);
            int b = recurPath(obstacleGrid, i, j - 1);
//            cout << i << ' ' << j << ',' << a << ' ' << b << endl;
            obstacleGrid[i][j] = (a != -2 ? a : 0) + (b != -2 ? b : 0);
        }
        return obstacleGrid[i][j];
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty()) {
            return 1;
        }
        int M = int(obstacleGrid.size());
        int N = int(obstacleGrid[0].size());
        
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    obstacleGrid[i][j] = -2;
                }else{
                    obstacleGrid[i][j] = -1;
                }
            }
        }
        
        if (obstacleGrid[0][0] != -2) {
            obstacleGrid[0][0] = 1;
        }else{
            return 0;
        }
        
        for (int i = 1; i < M; ++i) {
            if (obstacleGrid[i][0] != -2) {
                obstacleGrid[i][0] = obstacleGrid[i - 1][0];
            }
        }
        
        for (int j = 1; j < N; ++j) {
            if (obstacleGrid[0][j] != -2) {
                obstacleGrid[0][j] = obstacleGrid[0][j - 1];
            }
        }
        int result = recurPath(obstacleGrid, M - 1, N - 1);
        return result != -2 ? result : 0;
    }
};

int main(int argc, const char * argv[]) {
//    const int M = 5;
//    const int N = 5;
//    int array[M][N] = {
//        {0, 0, 1, 0, 0},
//        {0, 0, 0, 0, 0},
//        {1, 0, 0, 0, 0},
//        {0, 1, 0, 0, 0},
//        {0, 0, 0, 0, 0}
//    };
    const int M = 1;
    const int N = 2;
    int array[M][N] = {
        {0, 1}
    };
//    const int M = 22;
//    const int N = 33;
//    int array[M][N] = {        {0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0},{1,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0,0,1,0,0,1},{0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0},{0,0,0,1,0,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,1,0},{1,0,1,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0},{0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,0},{0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,1,0,0,0,0,0},{0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},{1,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,1},{0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,1,0,0,0,0,0},{0,1,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,0,0,0,0,0},{0,1,0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,0,1},{1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,1,0,0,1,0,0,0,0,0,0},{0,0,1,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,1,1,0,1,0,0,0,0,1,1},{0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,0,1,0,1},{1,1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,1,0,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,1},{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,1,0,0,0}
//    };
    vector<vector<int>>obstacleGrid;
    for (int i = 0; i < M; ++i) {
        obstacleGrid.push_back(vector<int>(array[i], array[i] + N));
    }
    Solution s;
    cout << s.uniquePathsWithObstacles(obstacleGrid) << endl;
    return 0;
}
