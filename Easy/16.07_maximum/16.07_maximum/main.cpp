//
//  main.cpp
//  16.07_maximum
//
//  Created by bella on 2020/8/28.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
using namespace std;
class Solution {
public:
    int maximum(int a, int b) {
        bool sign = ((a & 0x80000000) ^ (b & 0x80000000));
        bool result = (sign && (b & 0x80000000)) || ((sign ^ 1) && (((a - b) & 0x80000000) ^ 0x80000000));
        return result * a + (result ^ 1) * b;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.maximum(2147483647 ,-2147483648) << endl;
    cout << s.maximum(2147483647 ,2147483646) << endl;
    cout << s.maximum(-2147483647 ,-2147483648) << endl;
    cout << s.maximum(-73383683 ,-2537) << endl;
    cout << s.maximum(-1758650493 ,96404) << endl;
    return 0;
}
