//
//  main.cpp
//  62_uniquePaths
//
//  Created by Bella Yang on 2019/9/16.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1) {
            return 1;
        }
        // (m-1)*(n-1)的二维vector
        vector<vector<int>> nums(m - 1, vector<int>(n - 1));
        
        for (int i = 0; i < m - 1; ++i) {
            for (int j = 0; j < n - 1; ++j) {
                nums[i][j] = (i == 0 ? 1 : nums[i - 1][j]) + (j == 0 ? 1 : nums[i][j - 1]);
            }
        }
        
        return nums[m - 2][n - 2];
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.uniquePaths(7, 3) << endl;
    return 0;
}
