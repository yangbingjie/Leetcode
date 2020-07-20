//
//  main.cpp
//  1252_oddCells
//
//  Created by bella on 2020/7/20.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<bool>row(n, false);
        vector<bool>col(m, false);
        for (int i = 0; i < indices.size(); ++i) {
            row[indices[i][0]] = !row[indices[i][0]];
            col[indices[i][1]] = !col[indices[i][1]];
        }
        int num = 0;
        for (int i = 0; i < row.size(); ++i) {
            for (int j = 0; j < col.size(); ++j) {
                if (row[i] != col[j]) {
                    num++;
                }
            }
        }
        return num;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    const int LEN1 = 2;
    const int LEN2 = 2;
    int arr[LEN1][LEN2] = {{0,1},{1,1}};
    vector<vector<int>>indices(LEN1, vector<int>(LEN2));
    for (int i = 0; i < LEN1; ++i) {
        indices[i] = vector<int>(arr[i], arr[i] + LEN2);
    }
    cout << s.oddCells(2, 3, indices) << endl;
    return 0;
}
