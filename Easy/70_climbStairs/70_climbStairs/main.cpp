//
//  main.cpp
//  70_climbStairs
//
//  Created by Bella Yang on 2019/9/11.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }
        int a = 1;
        int b = 2;
        int result = 0;
        for (int i = 3; i <= n; ++i) {
            result = a + b;
            a = b;
            b = result;
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.climbStairs(10);
    return 0;
}
