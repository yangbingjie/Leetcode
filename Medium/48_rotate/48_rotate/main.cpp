//
//  main.cpp
//  48_rotate
//
//  Created by Bella Yang on 2019/9/8.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int len = int(matrix.size());
        int value;
        int x;
        int y;
        int tmp;
        for (int i = 0; i < (len + 1) / 2; ++i) {
            for (int j = len - i - 2; j - i >= 0 ; --j) {
                value = matrix[i][j];
                x = i;
                y = j;
                for (int k = 0; k < 3; ++k) {
                    tmp = len - 1 - y;
                    matrix[x][y] = matrix[tmp][x];
                    y = x;
                    x = tmp;
                }
                matrix[x][y] = value;
            }
        }
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
//    const int LEN = 4;
//    int array[LEN][LEN] = {
//        { 5, 1, 9,11},
//        { 2, 4, 8,10},
//        {13, 3, 6, 7},
//        {15,14,12,16}
//    };
    
    const int LEN = 1;
    int array[LEN][LEN] = {
        { 5},
    };
    
    vector<vector<int>> matrix;
    
    for (int i = 0; i < LEN; ++i) {
        matrix.push_back(vector<int>(array[i], array[i] + LEN));
    }
    s.rotate(matrix);
    return 0;
}
