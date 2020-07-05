//
//  main.cpp
//  343_integerBreak
//
//  Created by bella on 2020/7/5.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int integerBreak(int n) {
        vector<int>vec(n + 1, 0);
        vec[1] = 1;
        vec[2] = 1;
        for (int i = 3; i <= n; ++i) {
            vec[i] = 0;
            for (int j = 1; j < i; ++j) {
                int tmp = max(vec[j], j) * max(vec[i - j], (i - j));
                if (tmp > vec[i]) {
                    vec[i] = tmp;
                }
            }
        }
        return vec[n];
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.integerBreak(8) << endl;
    return 0;
}
