//
//  main.cpp
//  650_minSteps
//
//  Created by bella on 2020/7/9.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;
class Solution {
public:
    int minSteps(int n) {
        int steps = 0;
        int i = 2;
        while (n != 1) {
            i = 2;
            while (n != 1) {
                if (n % i == 0) {
                    n = n / i;
                    steps += i;
                    break;
                }else{
                    i++;
                }
            }
        }
        return steps;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.minSteps(3) << endl;
    return 0;
}
