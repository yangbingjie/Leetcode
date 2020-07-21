//
//  main.cpp
//  447_numberOfBoomerangs
//
//  Created by bella on 2020/7/21.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        vector<map<int, int>>v(points.size(), map<int, int>());
        map<int, int>::iterator iter1;
        map<int, int>::iterator iter2;
        int dist;
        int num = 0;
        for (int i = 0; i < points.size(); ++i) {
            for (int j = i + 1; j < points.size(); ++j) {
                if (i == j) {
                    continue;
                }
                dist = (points[i][0] - points[j][0]) * (points[i][0] - points[j][0]) + (points[i][1] - points[j][1]) * (points[i][1] - points[j][1]);
                iter1 = v[i].find(dist);
                iter2 = v[j].find(dist);
                if (iter1 != v[i].end()) {
                    iter1->second++;
                }else{
                    v[i][dist] = 1;
                }
                if (iter2 != v[j].end()) {
                   iter2->second++;
               }else{
                   v[j][dist] = 1;
               }
            }
        }
        for (int i = 0; i < v.size(); ++i) {
            iter1 = v[i].begin();
            while (iter1 != v[i].end()) {
                num += iter1->second * (iter1->second - 1);
                iter1++;
            }
        }
        return num;
    }
};
int main(int argc, const char * argv[]) {
    const int LEN1 = 5;
    const int LEN2 = 2;
//    int arr[LEN1][LEN2] = {{0,0},{1,0},{2,0}};
    int arr[LEN1][LEN2] = {{0,0},{1,0},{-1,0},{0,1},{0,-1}};
    vector<vector<int>>points(LEN1, vector<int>(LEN2));
    for (int i = 0; i < LEN1; ++i) {
        points[i] = vector<int>(arr[i], arr[i]+LEN2);
    }
    Solution s;
    cout << s.numberOfBoomerangs(points) << endl;
    return 0;
}
