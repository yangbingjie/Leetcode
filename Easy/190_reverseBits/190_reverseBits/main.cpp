//
//  main.cpp
//  190_reverseBits
//
//  Created by Bella Yang on 2019/11/6.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for(int i = 0; i < 32; ++i){
            result = result << 1;
            result += n & 1;
            n = n >> 1;
        }
        return result;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    std::cout << s.reverseBits(43261596) << std::endl;
    return 0;
}
