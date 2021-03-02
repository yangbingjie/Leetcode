//
//  main.cpp
//  304_sumRegion
//
//  Created by Bella Yang on 2021/3/2.
//

#include <iostream>
#include <vector>
using namespace std;
class NumMatrix {
private:
    vector<vector<int>> sum;
public:
    NumMatrix(vector<vector<int>>& matrix): sum(matrix){
        if(matrix.empty() || matrix[0].empty()){
            return;
        }
        for(int i = 1; i < matrix.size(); ++i){
            sum[i][0] += sum[i - 1][0];
        }
        for(int j = 1; j < matrix[0].size(); ++j){
            sum[0][j] += sum[0][j - 1];
        }

        for(int i = 1; i < matrix.size(); ++i){
            for(int j = 1; j < matrix[0].size();++j){
                sum[i][j] += sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1];
                // cout << sum[i][j] << ", ";
            }
            // cout << endl;
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int result = sum[row2][col2];
        if(col1 > 0){
            result -= sum[row2][col1 - 1];
        }
        if(row1 > 0){
            result -= sum[row1 - 1][col2];
        }
        if(col1 > 0 && row1 > 0){
            result += sum[row1 - 1][col1 - 1];
        }
        return result;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
int main(int argc, const char * argv[]) {
    vector<vector<int>>matrix = {
        {3, 0, 1, 4, 2},
        {5, 6, 3, 2, 1},
        {1, 2, 0, 1, 5},
        {4, 1, 0, 1, 7},
        {1, 0, 3, 0, 5}};
    NumMatrix* obj = new NumMatrix(matrix);
    cout << obj->sumRegion(2,1,4,3) << endl;
    return 0;
}
