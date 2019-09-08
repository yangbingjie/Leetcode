//
//  main.cpp
//  69_mySqrt
//
//  Created by Bella Yang on 2019/9/8.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
using namespace std;
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) {
            return 0;
        }
        int left = 1;
        int right = int(x / 2 + 1);
        long long mid;
        while (right - left > 1) {
            mid = int((left + right) / 2);
            if (mid * mid > x) {
                right = int(mid);
            }else{
                left = int(mid);
            }
        }
        return left;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.mySqrt(10);
    return 0;
}
