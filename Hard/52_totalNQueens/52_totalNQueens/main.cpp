//
//  main.cpp
//  52_totalNQueens
//
//  Created by bella on 2020/8/12.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
private:
    int N;
    int result;
public:
    bool check(vector<vector<bool>>&tmp, int x, int y){
        for (int i = 0; i < x; ++i) {
            if (tmp[i][y] == true) {
                return false;
            }
        }
        for (int j = 0; j < y; ++j) {
            if (tmp[x][j] == true) {
                return false;
            }
        }
        for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; i--,j--) {
            if (tmp[i][j] == true) {
                return false;
            }
        }
        for (int i = x - 1, j = y + 1; i >= 0 && j < N; i--,j++) {
            if (tmp[i][j] == true) {
                return false;
            }
        }
        return true;
    }
    void recur(vector<vector<bool>>&tmp, int row){
        if (row == N) {
            result++;
            return;
        }
        for(int i = 0; i < N; ++i){
            tmp[row][i] = true;
            if (check(tmp, row, i)) {
                recur(tmp, row + 1);
            }
            tmp[row][i] = false;
        }
    }
    int totalNQueens(int n) {
        vector<vector<bool>>tmp(n, vector<bool>(n, false));
        N = n;
        recur(tmp, 0);
        return result;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.totalNQueens(8) << endl;
    return 0;
}
