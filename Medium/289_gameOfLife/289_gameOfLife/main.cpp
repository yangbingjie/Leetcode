//
//  main.cpp
//  289_gameOfLife
//
//  Created by Bella Yang on 2020/10/9.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
private:
    static const int LEN = 8;
    int diff_x[LEN] = {-1,-1,-1, 0, 0, 1, 1, 1};
    int diff_y[LEN] = {-1, 0, 1,-1, 1,-1, 0, 1};
public:
    void gameOfLife(vector<vector<int>>& board) {
        // old mid new
        //  0   2   0
        //  0   3   1
        //  1   4   0
        //  1   5   1
        int neighbor;
        int xx;
        int yy;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                neighbor = 0;
                for (int k = 0; k < LEN; ++k) {
                    xx = i + diff_x[k];
                    yy = j + diff_y[k];
                    if (xx >= 0 && yy >= 0 && xx < board.size() && yy < board[0].size() && (board[xx][yy] == 1 || board[xx][yy] == 4 || board[xx][yy] == 5)) {
                        neighbor++;
                    }
                }
                if (board[i][j] == 1) {
                    board[i][j] = (neighbor == 2 || neighbor == 3) ? 5 : 4;
                }else{
                    board[i][j] = (neighbor == 3) ? 3 : 2;
                }
            }
        }
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == 2 || board[i][j] == 4) {
                    board[i][j] = 0;
                }else{
                    board[i][j] = 1;
                }
            }
        }
    }
};
int main(int argc, const char * argv[]) {
    vector<vector<int>> board = {
        {0,1,0},
        {0,0,1},
        {1,1,1},
        {0,0,0}
    };
    Solution s;
    s.gameOfLife(board);
    return 0;
}
