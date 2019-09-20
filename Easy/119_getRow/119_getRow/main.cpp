//
//  main.cpp
//  119_getRow
//
//  Created by Bella Yang on 2019/9/20.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(1, 1);
        if (rowIndex == 0) {
            return result;
        }
        vector<int>tmp(2, 1);
        if (rowIndex == 1) {
            return tmp;
        }
        for (int row = 2; row < rowIndex + 1; ++row) {
            result.clear();
            result.push_back(1);
            for (int col = 0; col < row - 1; ++col) {
                result.push_back(tmp[col] + tmp[col + 1]);
            }
            result.push_back(1);
            tmp.assign(result.begin(), result.end());
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    s.getRow(4);
    return 0;
}

