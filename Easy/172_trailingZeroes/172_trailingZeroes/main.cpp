//
//  main.cpp
//  172_trailingZeroes
//
//  Created by Bella Yang on 2019/10/22.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
class Solution {
public:
    int trailingZeroes(int n) {
        if(n < 5){
            return 0;
        }
        return (n / 5) + trailingZeroes(n / 5) ;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    std::cout << s.trailingZeroes(100)<<std::endl;
    return 0;
}
