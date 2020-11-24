//
//  main.cpp
//  452_findMinArrowShots
//
//  Created by Bella Yang on 2020/11/23.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](vector<int>p1,vector<int>p2){
            return p1[1] < p2[1];
        });
        int arrow = 0;
        int ind;
        for (int i = 0; i < points.size();) {
            arrow++;
            ind = i;
            ++i;
            while (i < points.size() && points[i][0] <= points[ind][1]) {
                ++i;
            }
        }
        return arrow;
    }
};
int main(int argc, const char * argv[]) {
//    vector<vector<int>>points = {{10,16},{2,8},{1,6},{7,12},{100,101}};
    vector<vector<int>>points = {{31176229,84553602},{59484421,74029340},{8413784,65312321},{34575198,108169522},{49798315,88462685},{29566413,114369939},{12776091,37045071},{11759956,61001829},{37806862,80806032},{82906996,118404277}};
    Solution s;
    cout << s.findMinArrowShots(points) << endl;
    return 0;
}
