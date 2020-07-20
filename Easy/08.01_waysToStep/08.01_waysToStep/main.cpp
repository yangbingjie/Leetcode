//
//  main.cpp
//  08.01_waysToStep
//
//  Created by bella on 2020/7/20.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
using namespace std;
class Solution {
public:
    int waysToStep(int n) {
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }
        if (n == 3) {
            return 4;
        }
        int one = 1;
        int two = 2;
        int three = 4;
        int result = -1;
        for (int i = 4; i <= n; ++i) {
            result = (((three % 1000000007) + (two % 1000000007)) % 1000000007 + (one % 1000000007))% 1000000007;
            one = two;
            two = three;
            three = result;
        }
        return result;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.waysToStep(61) << endl;
    return 0;
}
