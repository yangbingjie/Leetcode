//
//  main.cpp
//  441_arrangeCoins
//
//  Created by Bella Yang on 2019/11/28.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        return int((sqrt(1 + 8 * long(n)) - 1) / 2);
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.arrangeCoins(1804289383) << endl;
    return 0;
}
