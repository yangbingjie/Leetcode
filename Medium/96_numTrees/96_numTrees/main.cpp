//
//  main.cpp
//  96_numTrees
//
//  Created by bella on 2020/7/15.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int numTrees(int n) {
        vector<int>vec(n + 1);

        if (n >= 1) {
            vec[0] = 1;
            vec[1] = 1;
        }
        if (n >= 2) {
            vec[2] = 2;
        }
        for (int i = 3; i <= n; ++i) {
            vec[i] = 0;
            for (int j = 0; j < i; ++j) {
                vec[i] += vec[j] * vec[i - 1 - j];
            }
        }
        return vec[n];
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.numTrees(2) << endl;
    return 0;
}
