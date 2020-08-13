//
//  main.cpp
//  51_solveNQueens
//
//  Created by bella on 2020/8/12.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
private:
    int N;
public:
    bool check(vector<string>&tmp, int x, int y){
        for (int i = 0; i < x; ++i) {
            if (tmp[i][y] == 'Q') {
                return false;
            }
        }
        for (int j = 0; j < y; ++j) {
            if (tmp[x][j] == 'Q') {
                return false;
            }
        }
        for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; i--,j--) {
            if (tmp[i][j] == 'Q') {
                return false;
            }
        }
        for (int i = x - 1, j = y + 1; i >= 0 && j < N; i--,j++) {
            if (tmp[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
    void recur(vector<vector<string>>& result, vector<string>&tmp, int row){
        if (row == N) {
            result.push_back(tmp);
            return;
        }
        for(int i = 0; i < N; ++i){
            tmp[row][i] = 'Q';
            if (check(tmp, row, i)) {
                recur(result, tmp, row + 1);
            }
            tmp[row][i] = '.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        string str = "";
        for (int i = 0; i < n; ++i) {
            str += ".";
        }
        vector<string>tmp(n, str);
        N = n;
        recur(result, tmp, 0);
        return result;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    s.solveNQueens(4);
    return 0;
}
