//
//  main.cpp
//  1351_countNegatives
//
//  Created by bella on 2020/8/23.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int binarySearch(vector<int>&vec, int begin, int end){
        int mid;
        while(begin < end){
            mid = begin + (end - begin) / 2;
            if((mid == begin && vec[mid] < 0) || (mid - 1 >= 0 && vec[mid - 1] >= 0 && vec[mid] < 0)){
                return mid;
            }else if (vec[mid] < 0){
                end = mid;
            }else{
                begin = mid + 1;
            }
        }
        return vec.size();
    }
    int countNegatives(vector<vector<int>>& grid) {
        int total = 0;
        int start = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = m - 1; i >= 0; --i){
            start = binarySearch(grid[i], start, n);
            if(start == n){
                break;
            }
            total += n - start;
        }
        return total;
    }
};
int main(int argc, const char * argv[]) {
    const int LEN1 = 2;
    const int LEN2 = 3;
//    int arr[LEN1][LEN2] = {
//        {4,3,2,-1},{3,2,1,-1},{1,1,-1,-2},{-1,-1,-2,-3}
//    };
//    int arr[LEN1][LEN2] = {{3,2},{1,0}};
    int arr[LEN1][LEN2] = {5,1,0,-5,-5,-5};
    vector<vector<int>>vec;
    for (int i = 0; i < LEN1; ++i) {
        vec.push_back(vector<int>(arr[i], arr[i] + LEN2));
    }
    Solution s;
    cout << s.countNegatives(vec) << endl;
    return 0;
}
