//
//  main.cpp
//  16.11_divingBoard
//
//  Created by bella on 2020/7/8.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        vector<int>result;
        if (k == 0) {
            return result;
        }
        if (shorter == longer) {
            result.push_back(shorter * k);
            return result;
        }
        int num;
        result.push_back(shorter * k);
        for (int i = 1; i <= k; ++i) {
            num = result[i - 1] + longer - shorter;
            result.push_back(num);
        }
        return result;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    s.divingBoard(1, 10, 3);
    return 0;
}
