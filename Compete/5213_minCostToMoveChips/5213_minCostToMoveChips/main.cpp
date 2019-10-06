//
//  main.cpp
//  5213_minCostToMoveChips
//
//  Created by Bella Yang on 2019/10/6.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        int odd = 0;
        int even = 0;
        for (int i = 0; i < chips.size(); ++i) {
            if (chips[i] % 2 == 0) {
                odd++;
            }else{
                even++;
            }
        }
        return min(odd, even);
    }
};
int main(int argc, const char * argv[]) {
    const int LEN = 3;
    int array[LEN] = {1,2,3};
    vector<int> vec(array, array + LEN);
    Solution s;
    cout << s.minCostToMoveChips(vec);
    return 0;
}
