//
//  main.cpp
//  36_isValidSudoku
//
//  Created by Bella Yang on 2019/9/5.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isUnique(vector<char>& array){
        if (array.empty()) {
            return true;
        }
        sort(array.begin(), array.end());
        char tmp = array[0];
        for (int i = 1; i < array.size(); ++i) {
            if (tmp == array[i]) {
                return false;
            }else{
                tmp = array[i];
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        const int LEN = 9;
        vector<char> tmp;
        for (int i = 0; i < LEN; ++i) {
            tmp.clear();
            for (int j = 0; j < LEN; ++j) {
                if (board[i][j] != '.') {
                    tmp.push_back(board[i][j]);
                }
            }
            if (!isUnique(tmp)) {
                return false;
            }
        }
        
        for (int i = 0; i < LEN; ++i) {
            tmp.clear();
            for (int j = 0; j < LEN; ++j) {
                if (board[j][i] != '.') {
                    tmp.push_back(board[j][i]);
                }
            }
            if (!isUnique(tmp)) {
                return false;
            }
        }
        
        int x;
        int y;
        
        for (int i = 0; i < LEN / 3; ++i) {
            for (int j = 0; j < LEN / 3; ++j) {
                tmp.clear();
                for (int m = 0; m < LEN / 3; ++m) {
                    for (int n = 0; n < LEN / 3; ++n) {
                        x = i * LEN / 3 + m;
                        y = j * LEN / 3 + n;
                        if (board[x][y] != '.') {
                            tmp.push_back(board[x][y]);
                        }
                    }
                }
                if (!isUnique(tmp)) {
                    return false;
                }
            }
        }
        
        return true;
    }
};

int main(int argc, const char * argv[]) {
    const int LEN = 9;
    vector<vector<char>>board;
    char array[LEN][LEN] = {
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
    for (int i = 0; i < LEN; ++i) {
        board.push_back(vector<char>(array[i], array[i] + LEN));
    }
    Solution s;
    cout<< s.isValidSudoku(board) << endl;
    return 0;
}
