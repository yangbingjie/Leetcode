//
//  main.cpp
//  476_findComplement
//
//  Created by bella on 2020/8/21.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
using namespace std;
class Solution {
public:
    int findComplement(int num) {
        int n = num;
        long ones = 0xFFFFFFFF;
        while (n!=0) {
            n >>= 1;
            ones <<= 1;
        }
        return ~(ones ^ num);
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.findComplement(100) << endl;
    return 0;
}
