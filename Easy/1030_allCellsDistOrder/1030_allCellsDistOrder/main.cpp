//
//  main.cpp
//  1030_allCellsDistOrder
//
//  Created by Bella Yang on 2020/11/17.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>>result;
        const int diff_x[4] = {1,1,-1,-1};
        const int diff_y[4] = {1,-1,-1,1};
        result.push_back({r0, c0});
        int xx = r0;
        int yy = c0;
        int max_dist = max(r0, R - 1 - r0) + max(c0, C - 1 - c0);
        for (int dist = 1; dist <= max_dist; ++dist) {
            xx = r0 - dist;
            yy = c0;
            for (int i = 0; i < 4; ++i) {
                for (int j = dist; j > 0; --j) {
                    if (xx >= 0 && yy >= 0 && xx < R && yy < C) {
                        result.push_back({xx, yy});                        
                    }
                    xx += diff_x[i];
                    yy += diff_y[i];
                }
            }
        }
        return result;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    s.allCellsDistOrder(2, 3, 1, 2);
    return 0;
}
