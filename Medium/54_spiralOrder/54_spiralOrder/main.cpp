//
//  main.cpp
//  54_spiralOrder
//
//  Created by Bella Yang on 2019/9/9.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty()) {
            return result;
        }
        int x_max = int(matrix.size());
        int y_max = int(matrix[0].size());
        int x_min = 0;
        int y_min = 0;
        int count = x_max * y_max;
        for (int i = -1, j = -1; result.size() < count; y_min++,x_max--,y_max--) {
            for (++i, ++j; j < y_max && result.size() < count; ++j) {
                result.push_back(matrix[i][j]);
            }
            
            for (++i, --j; i < x_max && result.size() < count; ++i) {
                result.push_back(matrix[i][j]);
            }
            
            for (--i, --j; j >= y_min && result.size() < count; --j) {
                result.push_back(matrix[i][j]);
            }
            
            for (x_min++, --i, ++j; i >= x_min && result.size() < count; --i) {
                result.push_back(matrix[i][j]);
            }
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    const int M = 3;
    const int N = 4;
    int array[M][N] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9,10,11,12}
    };
    vector<vector<int>>matrix;
    for (int i = 0; i < M; ++i) {
        matrix.push_back(vector<int>(array[i], array[i] + N));
    }
    Solution s;
    s.spiralOrder(matrix);
    return 0;
}
