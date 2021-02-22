//
//  main.cpp
//  766_isToeplitzMatrix
//
//  Created by Bella Yang on 2021/2/22.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 1; i + j < m && j < n; ++j) {
                if (matrix[i + j][j] != matrix[i][0]) {
                    return false;
                }
            }
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 1; i + j < n && j < m; ++j) {
                if (matrix[j][i + j] != matrix[0][i]) {
                    return false;
                }
            }
        }
        return true;
    }
};
int main(int argc, const char * argv[]) {
    vector<vector<int>>matrix = {
        {1,2,3,4},{5,1,2,3},{9,5,1,2}};
    Solution s;
    cout << s.isToeplitzMatrix(matrix) << endl;
    return 0;
}
