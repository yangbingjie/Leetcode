//
//  main.cpp
//  836_isRectangleOverlap
//
//  Created by bella on 2020/8/18.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return rec2[0] < rec1[2] && rec2[1] < rec1[3] && rec2[2] > rec1[0] && rec2[3] > rec1[1];
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    const int LEN = 4;
    int arr1[LEN] = {7,8,13,15};
    int arr2[LEN] = {10,8,12,20};
    vector<int>vec1(arr1,arr1+LEN);
    vector<int>vec2(arr2, arr2 + LEN);
    cout << s.isRectangleOverlap(vec1, vec2) << endl;
    return 0;
}
