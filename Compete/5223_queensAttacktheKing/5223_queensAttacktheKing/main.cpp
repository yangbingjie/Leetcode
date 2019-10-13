//
//  main.cpp
//  5223_queensAttacktheKing
//
//  Created by Bella Yang on 2019/10/13.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>>result;
        vector<vector<bool>> has_queens(8,vector<bool>(8,false));
        for (int i = 0; i < queens.size(); ++i) {
                has_queens[queens[i][0]][queens[i][1]] = true;
        }
        vector<int>tmp;
        for (int i = king[0]; i >= 0; i--) {
            if (has_queens[i][king[1]]) {
                tmp.clear();
                tmp.push_back(i);
                tmp.push_back(king[1]);
                result.push_back(tmp);
                break;
            }
        }
        for (int i = king[0]; i < 8; i++) {
            if (has_queens[i][king[1]]) {
                tmp.clear();
                tmp.push_back(i);
                tmp.push_back(king[1]);
                result.push_back(tmp);
                break;
            }
        }
        for (int j = king[1]; j >= 0; j--) {
            if (has_queens[king[0]][j]) {
                tmp.clear();
                tmp.push_back(king[0]);
                tmp.push_back(j);
                result.push_back(tmp);
                break;
            }
        }
        for (int j = king[1]; j < 8; j++) {
            if (has_queens[king[0]][j]) {
                tmp.clear();
                tmp.push_back(king[0]);
                tmp.push_back(j);
                result.push_back(tmp);
                break;
            }
        }
        for (int i = king[0], j = king[1]; i >= 0 && j >= 0; i--, j--) {
            if (has_queens[i][j]) {
                tmp.clear();
                tmp.push_back(i);
                tmp.push_back(j);
                result.push_back(tmp);
                break;
            }
        }
        for (int i = king[0], j = king[1]; i < 8 && j < 8; i++, j++) {
            if (has_queens[i][j]) {
                tmp.clear();
                tmp.push_back(i);
                tmp.push_back(j);
                result.push_back(tmp);
                break;
            }
        }
        for (int i = king[0], j = king[1]; i >= 0 && j < 8; i--, j++) {
            if (has_queens[i][j]) {
                tmp.clear();
                tmp.push_back(i);
                tmp.push_back(j);
                result.push_back(tmp);
                break;
            }
        }
        for (int i = king[0], j = king[1]; i < 8 && j >= 0; i++, j--) {
            if (has_queens[i][j]) {
                tmp.clear();
                tmp.push_back(i);
                tmp.push_back(j);
                result.push_back(tmp);
                break;
            }
        }

        return result;
    }
};
int main(int argc, const char * argv[]) {
    int array[34][2] = {{5,6},{7,7},{2,1},{0,7},{1,6},{5,1},{3,7},{0,3},{4,0},{1,2},{6,3},{5,0},{0,4},{2,2},{1,1},{6,4},{5,4},{0,0},{2,6},{4,5},{5,2},{1,4},{7,5},{2,3},{0,5},{4,2},{1,0},{2,7},{0,1},{4,6},{6,1},{0,6},{4,3},{1,7}};
    vector<vector<int>> queens;
    for (int i =0; i < 34; ++i) {
        queens.push_back(vector<int>(array[i], array[i] + 2));
    }
    vector<int> king;
    king.push_back(3);
    king.push_back(4);
    Solution s;
    s.queensAttacktheKing(queens, king);
    return 0;
}
