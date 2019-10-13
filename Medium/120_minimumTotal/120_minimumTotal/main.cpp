//
//  main.cpp
//  120_minimumTotal
//
//  Created by Bella Yang on 2019/10/13.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> lastMiniLen;
        lastMiniLen.push_back(triangle[0][0]);
        vector<int> miniLen;
        for (int i = 1; i < triangle.size(); ++i) {
            miniLen.clear();
            miniLen.push_back(triangle[i][0] + lastMiniLen[0]);
            for (int j = 1; j < i; ++j) {
                miniLen.push_back(triangle[i][j] + min(lastMiniLen[j - 1], lastMiniLen[j]));
            }
            miniLen.push_back(triangle[i][i] + lastMiniLen[i - 1]);
            lastMiniLen.clear();
            lastMiniLen = miniLen;
        }
        return *min_element(lastMiniLen.begin(), lastMiniLen.end());
    }
};
int main(int argc, const char * argv[]) {
    vector<vector<int>> triangle;
    int array1[1] = {2};
    triangle.push_back(vector<int>(array1, array1 + 1));
    int array2[2] = {3,4};
    triangle.push_back(vector<int>(array2, array2 + 2));
    int array3[3] = {6, 5, 7};
    triangle.push_back(vector<int>(array3, array3 + 3));
    int array4[4] = {4, 1, 8, 3};
    triangle.push_back(vector<int>(array4, array4 + 4));
    Solution s;
    cout << s.minimumTotal(triangle) << endl;
    return 0;
}
