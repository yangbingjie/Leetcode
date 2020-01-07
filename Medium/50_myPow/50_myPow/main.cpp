//
//  main.cpp
//  804_uniqueMorseRepresentations
//
//  Created by Bella Yang on 2020/1/7.
//  Copyright © 2020 Bella Yang. All rights reserved.
//

#include <iostream>
using namespace std;
class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0){
            return 1;
        }
        if(n == 1){
            return x;
        }
        if(n == -1){
            return 1 / x;
        }
        if(n % 2 == 1 || n % 2 == -1){
            if(n > 0){
                return x * myPow(x, n - 1);
            }else{
                return 1 / x * myPow(x, n + 1);
            }
        }else{
            double tmp = myPow(x, n / 2);
            return tmp * tmp;
        }
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.myPow(34.00515, -3) << endl;
    return 0;
}
