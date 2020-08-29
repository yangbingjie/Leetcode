//
//  main.cpp
//  1356_sortByBits
//
//  Created by bella on 2020/8/28.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    static bool less(int a, int b){
        int i = a;
        int j = b;
        while(i && j){
            i = i & (i - 1);
            j = j & (j - 1);
        }
        return i < j || (i == j && a < b);
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), less);
        return arr;
    }
};
int main(int argc, const char * argv[]) {
    const int LEN = 9;
    int arr[LEN] = {0,1,2,3,4,5,6,7,8};
    vector<int>vec(arr, arr +LEN);
    Solution s;
    s.sortByBits(vec);
    return 0;
}
