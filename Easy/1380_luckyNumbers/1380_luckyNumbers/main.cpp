//
//  main.cpp
//  1380_luckyNumbers
//
//  Created by bella on 2020/7/7.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int>lucky;
        int min_y;
        int min_num;
        bool is_max;
        for (int i = 0; i < matrix.size(); ++i) {
            min_num = matrix[i][0];
            min_y = 0;
            for (int j = 1; j < matrix[0].size(); ++j) {
                if (min_num > matrix[i][j]) {
                    min_num = matrix[i][j];
                    min_y = j;
                }
            }
            is_max = true;
            for (int k = 0; k < matrix.size(); ++k) {
                if (min_num < matrix[k][min_y]) {
                    is_max = false;
                }
            }
            if (is_max) {
                lucky.push_back(min_num);
            }
        }
        return lucky;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    const int LEN1 = 2;
    const int LEN2 = 2;
    int arr[LEN1][LEN2] = {{7, 8}, {1, 2}};
//    int arr[LEN1][LEN2] = {{3,7,8},{9,11,13},{15,16,17}};
//    int arr[LEN1][LEN2] = {{1,10,4,2},{9,3,8,7},{15,16,17,12}};
    vector<vector<int> > mat;
    for (int i = 0; i < LEN1; ++i) {
        mat.push_back(vector<int>(arr[i], arr[i] + LEN2));
    }
    Solution s;
    s.luckyNumbers(mat);
    return 0;
}
