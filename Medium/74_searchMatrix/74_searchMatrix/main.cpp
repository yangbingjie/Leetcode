//
//  main.cpp
//  74_searchMatrix
//
//  Created by Bella Yang on 2019/9/13.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) {
            return false;
        }
        int m = int(matrix.size());
        int n = int(matrix[0].size());
        int start = 0;
        int end = m * n;
        int mid;
        int x;
        int y;
        while (end - start >= 1) {
            mid = int((start + end) / 2);
            x = mid / n;
            y = mid % n;
            if (x < 0 || x >= m || y < 0 || y >= n) {
                break;
            }
            if (matrix[x][y] == target) {
                return true;
            }else if (matrix[x][y] < target){
                start = mid + 1;
            }else{
                end = mid;
            }
        }
        return false;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    const int M = 3;
    const int N = 4;
    vector<vector<int>> matrix;
    int array[M][N]={
        {1,   3,  5,  7},
        {10, 11, 16, 20},
        {23, 30, 34, 50}
    };
    for (int i = 0; i < M; ++i) {
        matrix.push_back(vector<int>(array[i], array[i] + N));
    }
    cout << s.searchMatrix(matrix, 23) << endl;
    return 0;
}
