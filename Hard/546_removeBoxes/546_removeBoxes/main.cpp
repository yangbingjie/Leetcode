//
//  main.cpp
//  546_removeBoxes
//
//  Created by bella on 2020/8/15.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
private:
    vector<vector<vector<int>>>dp;
public:
    int recur(vector<int>& boxes,int i, int j, int k){
        if(i > j){
            return 0;
        }
        if(dp[i][j][k] != 0){
            return dp[i][j][k];
        }
        // 尽可能缩小右边界j的范围
        while (i < j && boxes[j] == boxes[j - 1]) {
            j--;
            k++;
        }
        dp[i][j][k] = recur(boxes, i, j - 1, 0) + (k + 1) * (k + 1);
        for (int p = i; p < j; p++) {
            if (boxes[p] == boxes[j]) {
                dp[i][j][k] = max(dp[i][j][k], recur(boxes, p + 1, j - 1, 0) + recur(boxes, i, p, k + 1));
            }
        }
        return dp[i][j][k];
    }
    int removeBoxes(vector<int>& boxes) {
        int size = min(100, (int)boxes.size());
        dp = vector<vector<vector<int>>>(size,vector<vector<int>>(size,vector<int>(size,0)));
        return recur(boxes, 0, boxes.size() - 1, 0);
    }
};

int main(int argc, const char * argv[]) {
    const int LEN = 2;
    int arr[LEN] = {1,2};
    vector<int>vec(arr, arr + LEN);
    Solution s;
    cout << s.removeBoxes(vec) << endl;
    return 0;
}
