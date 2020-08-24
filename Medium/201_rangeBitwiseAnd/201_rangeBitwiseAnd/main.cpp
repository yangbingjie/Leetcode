//
//  main.cpp
//  201_rangeBitwiseAnd
//
//  Created by bella on 2020/8/23.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
using namespace std;
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int counts = 0;
        while (m != n) {
            m >>= 1;
            n >>= 1;
            counts++;
        }
        return m << counts;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.rangeBitwiseAnd(0, 2147483647) << endl;
    return 0;
}
