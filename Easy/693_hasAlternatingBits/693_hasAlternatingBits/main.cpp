//
//  main.cpp
//  693_hasAlternatingBits
//
//  Created by Bella Yang on 2019/12/16.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
class Solution {
public:
    bool hasAlternatingBits(int n) {
        int temp=n^(n>>1);
        return (temp&((long)temp+1))==0;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    std::cout << s.hasAlternatingBits(1431655765) << std::endl;
    return 0;
}
