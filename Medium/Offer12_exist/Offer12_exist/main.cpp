//
//  main.cpp
//  Offer12_exist
//
//  Created by Bella Yang on 2020/10/13.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
private:
    static const int LEN = 4;
    int diff_x[LEN] = {0,0,-1,1};
    int diff_y[LEN] = {-1,1,0,0};
public:
    bool dfs(vector<vector<char>>& board, int x, int y, string & word, int pos, vector<vector<bool>>& visited){
        if (pos == word.size()) {
            return true;
        }
        int xx;
        int yy;
        for (int i = 0; i < LEN; ++i) {
            xx = x + diff_x[i];
            yy = y + diff_y[i];
            if (xx >= 0 && xx < board.size() && yy >= 0 && yy < board[0].size() && board[xx][yy] == word[pos] && !visited[xx][yy]) {
                visited[xx][yy] = true;
                if (dfs(board, xx, yy, word, pos + 1, visited)) {
                    return true;
                }
                visited[xx][yy] = false;
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (word[0] == board[i][j]) {
                    visited[i][j] = true;
                    if (dfs(board, i, j, word, 1, visited)) {
                        return true;
                    }
                    visited[i][j] = false;
                }
            }
        }
        return false;
    }
};
int main(int argc, const char * argv[]) {
    vector<vector<char>>board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    Solution s;
    cout << s.exist(board, "ABCCED") << endl;
    return 0;
}
