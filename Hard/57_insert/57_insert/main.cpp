//
//  main.cpp
//  57_insert
//
//  Created by Bella Yang on 2020/11/4.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        bool is_add = false;
        int left = newInterval[0];
        int right = newInterval[1];
        for (int i = 0; i < intervals.size(); ++i) {
            if (intervals[i][0] > right) {
                if (!is_add) {
                    result.push_back({left, right});
                    is_add = true;
                }
                result.push_back(intervals[i]);
            }else if (intervals[i][1] < left){
                result.push_back(intervals[i]);
            }else{
                left = min(left, intervals[i][0]);
                right = max(right, intervals[i][1]);
            }
        }
        if (!is_add) {
            result.push_back({left, right});
        }
        return result;
    }
};
int main(int argc, const char * argv[]) {
    vector<vector<int>> intervals = {{1,5}};
    vector<int> newInterval = {2,3};
    Solution s;
    s.insert(intervals, newInterval);
    return 0;
}
