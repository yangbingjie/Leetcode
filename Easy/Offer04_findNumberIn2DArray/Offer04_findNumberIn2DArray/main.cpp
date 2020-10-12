//
//  main.cpp
//  Offer04_findNumberIn2DArray
//
//  Created by Bella Yang on 2020/10/11.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        int i = 0;
        int j = matrix[0].size() - 1;
        while (i < matrix.size() && j >= 0) {
            if (matrix[i][j] < target) {
                i++;
            }else if (matrix[i][j] > target){
                j--;
            }else{
                return true;
            }
        }
        return false;
    }
};
int main(int argc, const char * argv[]) {
    vector<vector<int>> matrix = {
        {1,   4,  7, 11, 15},
        {2,   5,  8, 12, 19},
        {3,   6,  9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    Solution s;
    cout << s.findNumberIn2DArray(matrix, 18) << endl;
    return 0;
}
