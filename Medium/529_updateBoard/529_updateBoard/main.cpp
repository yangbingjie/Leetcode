//
//  main.cpp
//  529_updateBoard
//
//  Created by bella on 2020/8/20.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
private:
    const static int LEN = 8;
    const int diff_x[LEN] = {-1,-1,0,1,1,1,0,-1};
    const int diff_y[LEN] = {0,1,1,1,0,-1,-1,-1};
public:
    void recur(vector<vector<char>>&board, int x, int y){
        int mine = 0;
        int xx,yy;
        for (int i = 0; i < LEN; ++i) {
            xx = x + diff_x[i];
            yy = y + diff_y[i];
            if (xx >= 0 && yy >= 0 && xx < board.size() && yy <board[0].size()) {
                if (board[xx][yy] == 'M' || board[xx][yy] == 'X') {
                    mine++;
                }
            }
        }
        if (mine != 0) {
            board[x][y] = mine + '0';
            return;
        }
        board[x][y] = 'B';
        for (int i = 0; i < LEN; ++i) {
            xx = x + diff_x[i];
            yy = y + diff_y[i];
            if (xx >= 0 && yy >= 0 && xx < board.size() && yy <board[0].size()) {
                if (board[xx][yy] == 'E') {
                    recur(board, xx, yy);
                }
            }
        }
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if (board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        }
        recur(board, click[0], click[1]);
        return board;
    }
};
int main(int argc, const char * argv[]) {
    const int LEN1 = 4;
    const int LEN2 = 5;
    char arr[LEN1][LEN2] = {
        {'B', '1', 'E', '1', 'B'},
            {'B', '1', 'M', '1', 'B'},
            {'B', '1', '1', '1', 'B'},
            {'B', 'B', 'B', 'B', 'B'}
    };
    vector<vector<char>>board;
    for (int i = 0; i < LEN1; ++i) {
        board.push_back(vector<char>(arr[i], arr[i] + LEN2));
    }
    vector<int>click;
    click.push_back(1);
    click.push_back(2);
    Solution s;
    s.updateBoard(board, click);
    return 0;
}
