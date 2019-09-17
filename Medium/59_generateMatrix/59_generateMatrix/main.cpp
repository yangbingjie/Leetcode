//
//  main.cpp
//  59_generateMatrix
//
//  Created by Bella Yang on 2019/9/17.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n));
        if (n == 0) {
            return result;
        }
        int length = n * n;
        int min = 0;
        n--;
        for (int num = 1, i = 0, j = 0; num <= length; ++num) {
            result[i][j] = num;
            if (i == min && j < n) {
                j++;
            }else if (j == n && i < n) {
                i++;
            }else if (i == n && j <= n && j > min) {
                j--;
            }else if(j == min && i > min + 1){
                i--;
            }else{
                min++;
                n--;
                j++;
            }
        }
        return result;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    s.generateMatrix(5);
    return 0;
}
