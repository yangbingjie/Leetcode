//
//  main.cpp
//  37_solveSudoku
//
//  Created by bella on 2020/9/15.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
private:
    vector<vector<bool>>row;
    vector<vector<bool>>col;
    vector<vector<vector<bool>>>block;
    vector<pair<int, int>>space;
public:
    bool dfs(vector<vector<char>>& board, int ind){
        if (ind == space.size()) {
            return true;
        }
        int x = space[ind].first;
        int y = space[ind].second;
        for (int i = 0; i < 9; ++i) {
            if (!row[x][i] && !col[y][i] && !block[x/3][y/3][i]) {
                board[x][y] = '1' + i;
                row[x][i] = col[y][i] = block[x/3][y/3][i] = true;
                if(dfs(board, ind + 1)){
                    return true;
                }
                row[x][i] = col[y][i] = block[x/3][y/3][i] = false;
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        row = vector<vector<bool>>(9, vector<bool>(9, false));
        col = vector<vector<bool>>(9, vector<bool>(9, false));
        block = vector<vector<vector<bool>>>(3,vector<vector<bool>>(3, vector<bool>(9, false)));
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    space.push_back(pair<int, int>(i, j));
                }else{
                    row[i][board[i][j] - '1'] = true;
                    col[j][board[i][j] - '1'] = true;
                    block[i/3][j/3][board[i][j] - '1'] = true;
                }
            }
        }
        dfs(board, 0);
    }
};
int main(int argc, const char * argv[]) {
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    Solution s;
    s.solveSudoku(board);
    return 0;
}
