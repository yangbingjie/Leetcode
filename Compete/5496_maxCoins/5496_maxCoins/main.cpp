//
//  main.cpp
//  5496_maxCoins
//
//  Created by bella on 2020/8/23.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int n = piles.size() / 3;
        int result = 0;
        for (int i = n; i < piles.size(); i += 2) {
            result += piles[i];
        }
        return result;
    }
};
int main(int argc, const char * argv[]) {
    const int LEN = 9;
    int arr[LEN] = {9,8,7,6,5,1,2,3,4};
    vector<int>piles(arr, arr + LEN);
    Solution s;
    cout << s.maxCoins(piles) << endl;
    return 0;
}
