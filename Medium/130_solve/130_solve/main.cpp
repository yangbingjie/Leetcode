//
//  main.cpp
//  130_solve
//
//  Created by bella on 2020/8/11.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;;
class Solution {
private:
    int m;
    int n;
    const static int LEN = 4;
    const int diffx[LEN] = {-1, 1, 0, 0};
    const int diffy[LEN] = {0, 0, -1, 1};
    vector<vector<bool>>is_visited;
public:
    bool check(int x, int y){
        return x >= 0 && x < m && y >= 0 && y < n;
    }
    void dfs(vector<vector<char>>& board, int x, int y){
        if (board[x][y] == 'O') {
            board[x][y] = 'R';
        }
        int xx;
        int yy;
        for (int i = 0; i < LEN; ++i) {
            xx = x + diffx[i];
            yy = y + diffy[i];
            if (check(xx, yy) && !is_visited[xx][yy] && board[xx][yy] == 'O') {
                is_visited[xx][yy] = true;
                dfs(board, xx, yy);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        m = (int)board.size();
        if (m == 0) {
            return;
        }
        n = (int)board[0].size();
        is_visited = vector<vector<bool>>(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            if (board[i][0] == 'O' && !is_visited[i][0]) {
                dfs(board, i, 0);
            }
            if (board[i][n - 1] == 'O' && !is_visited[i][n - 1]) {
                dfs(board, i, n - 1);
            }
        }
        for (int j = 1; j < n - 1; ++j) {
            if (board[0][j] == 'O' && !is_visited[0][j]) {
                dfs(board, 0, j);
            }
            if (board[m - 1][j] == 'O' && !is_visited[m - 1][j]) {
                dfs(board, m - 1, j);
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'R') {
                    board[i][j] = 'O';
                }else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
int main(int argc, const char * argv[]) {
    const int LEN1 = 4;
    const int LEN2 = 4;
    char arr[LEN1][LEN2] = {{'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}};
    vector<vector<char>>vec(LEN1, vector<char>(LEN2));
    for (int i = 0; i < LEN1; ++i) {
        vec[i]=vector<char>(arr[i], arr[i] + LEN2);
    }
    Solution s;
    s.solve(vec);
    return 0;
}
