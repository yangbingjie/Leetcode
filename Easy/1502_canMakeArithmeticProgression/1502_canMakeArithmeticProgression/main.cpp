//
//  main.cpp
//  1502_canMakeArithmeticProgression
//
//  Created by bella on 2020/7/23.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        if (arr.size() < 3) {
            return false;
        }
        sort(arr.begin(), arr.end());
        for (int i = 0; i + 2 < arr.size(); ++i) {
            if (2 * arr[i + 1] != arr[i + 2] + arr[i]) {
                return false;
            }
        }
        return true;
    }
};
int main(int argc, const char * argv[]) {
    const int LEN = 3;
    int arr[LEN] = {1, 5, 3};
    vector<int>v(arr, arr + LEN);
    Solution s;
    cout << s.canMakeArithmeticProgression(v) << endl;
    return 0;
}
