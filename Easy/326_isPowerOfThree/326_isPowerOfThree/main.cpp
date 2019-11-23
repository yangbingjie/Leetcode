//
//  main.cpp
//  326_isPowerOfThree
//
//  Created by Bella Yang on 2019/11/23.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;
class Solution {
public:
    bool isPowerOfThree(int n) {
        return (n > 0) && 1162261467 % n == 0;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.isPowerOfThree(387420489) << endl;
    return 0;
}
