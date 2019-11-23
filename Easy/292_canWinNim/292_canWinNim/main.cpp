//
//  main.cpp
//  292_canWinNim
//
//  Created by Bella Yang on 2019/11/23.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
class Solution {
public:
    bool canWinNim(int n) {
        return n % 4 != 0;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    std::cout << s.canWinNim(5) << std::endl;
    return 0;
}
