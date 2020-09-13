//
//  main.cpp
//  79_exist
//
//  Created by bella on 2020/9/13.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
private:
    int diff_x[4] = {0,0,1,-1};
    int diff_y[4] = {1,-1,0,0};
public:
    bool dfs(int x, int y, vector<vector<char>>& board, string & word, int start, vector<vector<bool>> & is_visited){
        if (start == word.size()) {
            return true;
        }
        int xx, yy;
        for (int i = 0; i < 4; ++i) {
            xx = x + diff_x[i];
            yy = y + diff_y[i];
            if (xx >= 0 && xx < board.size() && yy >= 0 && yy < board[0].size() && !is_visited[xx][yy] && board[xx][yy] == word[start]) {
                is_visited[xx][yy] = true;
                if (dfs(xx, yy, board, word, start + 1, is_visited)) {
                    return true;
                }
                is_visited[xx][yy] = false;
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> is_visited(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (word[0] == board[i][j]) {
                    is_visited[i][j] = true;
                    if(dfs(i, j, board, word, 1, is_visited)){
                        return true;
                    }
                    is_visited[i][j] = false;
                }
                
            }
        }
        return false;
    }
};
int main(int argc, const char * argv[]) {
    vector<vector<char>> vec = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    Solution s;
    cout << s.exist(vec, "ABCB") << endl;
    return 0;
}
