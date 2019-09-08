//
//  main.cpp
//  66_plusOne
//
//  Created by Bella Yang on 2019/9/8.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = int(digits.size() - 1); i >= 0; --i) {
            if (digits[i] != 9) {
                digits[i] += 1;
                return digits;
            }
            digits[i] = 0;
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main(int argc, const char * argv[]) {
    const int LEN = 3;
    int array[LEN] = {9, 9, 9};
    vector<int>digits(array, array + LEN);
    Solution s;
    s.plusOne(digits);
    return 0;
}
