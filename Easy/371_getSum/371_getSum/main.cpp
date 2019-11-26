//
//  main.cpp
//  371_getSum
//
//  Created by Bella Yang on 2019/9/28.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
using namespace std;
class Solution {
public:
    int getSum(int a, int b) {
        bool sign = true;
        if (a < 0 && b < 0) {
            sign = false;
        }
        int result = 0;
        int p = 0;
        int carry = 0;
        int pos = 1;
        while(true){
            p = (a & pos) ^ (b & pos) ^ carry;
            result |= p & pos;
            carry =  ((a & b) | (a & carry) | (carry & b)) & pos;
            if (pos > 0) {
                pos = pos << 1;
                carry = carry << 1;
            }else{
                break;
            }
        }
        return result;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.getSum(1, -9);
    return 0;
}
