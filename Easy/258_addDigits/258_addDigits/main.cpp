//
//  main.cpp
//  258_addDigits
//
//  Created by Bella Yang on 2019/11/22.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
using namespace std;
class Solution {
public:
    int addDigits(int num) {
        return (num == 0) ? 0 : ((num - 1) % 9 + 1);
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.addDigits(32) << endl;
    return 0;
}
