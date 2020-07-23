//
//  main.cpp
//  319_bulbSwitch
//
//  Created by bella on 2020/7/23.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;
class Solution {
public:
    int bulbSwitch(int n) {
        return sqrt(n);
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.bulbSwitch(3) << endl;
    return 0;
}
