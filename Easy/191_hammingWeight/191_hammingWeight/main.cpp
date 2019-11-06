//
//  main.cpp
//  191_hammingWeight
//
//  Created by Bella Yang on 2019/11/6.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int result = 0;
        for(int i = 0; i < 32; ++i){
            if((n & 1) == 1){
                result++;
            }
            n = n >> 1;
        }
        return result;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    std::cout << s.hammingWeight(11) << std::endl;
    return 0;
}
