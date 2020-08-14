//
//  main.cpp
//  605_canPlaceFlowers
//
//  Created by bella on 2020/8/14.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (flowerbed[0] == 0 && (flowerbed.size() == 1 || flowerbed[1] == 0)) {
            flowerbed[0] = 1;
            n--;
        }
        int i = 1;
        while (i < flowerbed.size() - 1) {
            if (flowerbed[i - 1] == 0 && flowerbed[i] == 0 && flowerbed[i + 1] == 0) {
                flowerbed[i] = 1;
                n--;
                if (n <= 0) {
                    return true;
                }
            }
            i++;
        }
        if (i == flowerbed.size() - 1 && flowerbed[i] == 0 && flowerbed[i - 1] == 0) {
            n--;
        }
        return n <= 0;
    }
};
int main(int argc, const char * argv[]) {
    const int LEN = 1;
    int arr[LEN] = {1};
    vector<int>vec(arr, arr + LEN);
    Solution s;
    cout << s.canPlaceFlowers(vec, 0) << endl;
    return 0;
}
