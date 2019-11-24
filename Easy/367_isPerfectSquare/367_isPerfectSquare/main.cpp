//
//  main.cpp
//  367_isPerfectSquare
//
//  Created by Bella Yang on 2019/11/23.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
class Solution {
public:
    bool isPerfectSquare(int num) {
        for (int i = 1; num > 0; i += 2) {
            num -= i;
        }
        return num == 0;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    std::cout << s.isPerfectSquare(132) << std::endl;
    return 0;
}
