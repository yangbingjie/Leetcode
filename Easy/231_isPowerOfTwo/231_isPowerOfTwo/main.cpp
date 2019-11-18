//
//  main.cpp
//  231_isPowerOfTwo
//
//  Created by Bella Yang on 2019/11/18.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
using namespace std;
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) {
            return false;
        }
        while (n > 1) {
            if ((n & 1) == 1) {
                return false;
            }
            n = n >> 1;
        }
        return true;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.isPowerOfTwo(3) << endl;
    return 0;
}
