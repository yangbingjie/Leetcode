//
//  main.cpp
//  342_isPowerOfFour
//
//  Created by Bella Yang on 2019/11/23.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
class Solution {
public:
    bool isPowerOfFour(int num) {
        // 0x55555555 is 1010 1010 1010 1010 1010 1010 1010 1010
        return (num > 0) && ((num & (num - 1)) == 0) && ((num & 0x55555555) != 0);
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    std::cout << s.isPowerOfFour(16);
    return 0;
}
