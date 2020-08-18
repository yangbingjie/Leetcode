//
//  main.cpp
//  733_floodFill
//
//  Created by bella on 2020/8/16.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
private:
    const static int LEN = 4;
    const int diff_x[LEN] = {-1,1,0,0};
    const int diff_y[LEN] = {0,0,-1,1};
public:
    void recur(vector<vector<int>>& image, int x, int y, int oldColor, int newColor){
        if (image[x][y] == oldColor) {
            image[x][y] = newColor;
            int xx;
            int yy;
            for (int i = 0; i < LEN; ++i) {
                xx = x + diff_x[i];
                yy = y + diff_y[i];
                if(xx >= 0 && yy >= 0 && xx < image.size() && yy < image[0].size()){
                    recur(image, xx , yy, oldColor, newColor);
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image[sr][sc] == newColor) {
            return image;
        }
        recur(image, sr, sc, image[sr][sc], newColor);
        return image;
    }
};
int main(int argc, const char * argv[]) {
    const int LEN1 = 2;
    const int LEN2 = 3;
    int arr[LEN1][LEN2] = {{0,0,0},{0,1,1}};
    vector<vector<int>>vec(LEN1);
    for (int i = 0; i < LEN1; ++i) {
        vec[i] = vector<int>(arr[i], arr[i] + LEN2);
    }
    Solution s;
    s.floodFill(vec, 1, 1, 1);
    return 0;
}
