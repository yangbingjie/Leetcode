//
//  main.cpp
//  73_setZeroes
//
//  Created by Bella Yang on 2019/9/12.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty()) {
            return;
        }
        bool hasZero;
        for (int i = 0; i < matrix.size(); ++i) {
            hasZero = false;
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == 0) {
                    hasZero = true;
                    break;
                }
            }
            if (hasZero) {
                for (int j = 0; j < matrix[0].size(); ++j) {
                    if (matrix[i][j] != 0) {
                        matrix[i][j] = 0xFFC00000;
                    }
                }
            }
        }
        
        
        for (int j = 0; j < matrix[0].size(); ++j) {
            hasZero = false;
            for (int i = 0; i < matrix.size(); ++i) {
                if (matrix[i][j] == 0) {
                    hasZero = true;
                    break;
                }
            }
            if (hasZero) {
                for (int i = 0; i < matrix.size(); ++i) {
                    if (matrix[i][j] != 0) {
                        matrix[i][j] = 0;
                    }
                }
            }
        }
        
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == 0xFFC00000) {
                    matrix[i][j] = 0;
                }
            }
        }
        
    }
};

int main(int argc, const char * argv[]) {
    const int M = 3;
    const int N = 4;
    int array[M][N] = {
        {0,1,2,0},
        {3,4,5,2},
        {1,3,1,5}
    };
    vector<vector<int>> matrix;
    for (int i = 0; i < M; ++i) {
        matrix.push_back(vector<int>(array[i], array[i] + N));
    }
    Solution s;
    s.setZeroes(matrix);
    return 0;
}
