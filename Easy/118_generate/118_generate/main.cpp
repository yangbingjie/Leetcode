//
//  main.cpp
//  118_generate
//
//  Created by Bella Yang on 2019/9/19.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if (numRows == 0) {
            return result;
        }
        result.push_back(vector<int>(1, 1));
        vector<int>tmp;
        for (int row = 1; row < numRows; ++row) {
            tmp.clear();
            tmp.push_back(1);
            for (int col = 0; col < row - 1; ++col) {
                tmp.push_back(result[row - 1][col] + result[row - 1][col + 1]);
            }
            tmp.push_back(1);
            result.push_back(tmp);
        }
        return result;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    s.generate(0);
    return 0;
}
