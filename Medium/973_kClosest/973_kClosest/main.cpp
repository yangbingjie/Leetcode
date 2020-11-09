//
//  main.cpp
//  973_kClosest
//
//  Created by Bella Yang on 2020/11/9.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    static bool compare(const vector<int>&p1,const vector<int>&p2){
        return p1[0] * p1[0] + p1[1] * p1[1] < p2[0] * p2[0] + p2[1] * p2[1];
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        sort(points.begin(), points.end(), compare);
        return vector<vector<int>>(points.begin(), points.begin() + K);
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<int>>points = {{3,3},{5,-1},{-2,4}};
    s.kClosest(points, 2);
    return 0;
}
