//
//  main.cpp
//  263_isUgly
//
//  Created by Bella Yang on 2019/9/28.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
using namespace std;
class Solution {
public:
    bool isUgly(int num) {
        if (num <= 0) {
            return false;
        }
        if (num == 1) {
            return true;
        }
        
        while (num % 5 == 0) {
            num /= 5;
        }
        while (num % 3 == 0) {
            num /= 3;
        }
        while (num % 2 == 0) {
            num /= 2;
        }
        return (num == 1) ? true : false;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.isUgly(14) << endl;
    return 0;
}
