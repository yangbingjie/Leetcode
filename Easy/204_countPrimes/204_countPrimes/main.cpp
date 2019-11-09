//
//  main.cpp
//  204_countPrimes
//
//  Created by Bella Yang on 2019/11/9.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int countPrimes(int n) {
        if (n < 2) {
            return 0;
        }
        vector<bool> is_primes(n, true);
        is_primes[0] = false;
        int count = n - 2;
        for (int i = 2; i * i < n; ++i) {
            for (int j = 2; j * i < n; ++j) {
                if (is_primes[j * i]) {
                    is_primes[j * i] = false;
                    count--;
                }
            }
        }
        return count;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.countPrimes(999983) << endl;
    return 0;
}
