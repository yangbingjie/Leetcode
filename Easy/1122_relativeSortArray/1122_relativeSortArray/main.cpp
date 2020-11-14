//
//  main.cpp
//  1122_relativeSortArray
//
//  Created by Bella Yang on 2020/11/14.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> m;
        for (int i = 0; i < arr2.size(); ++i) {
            m[arr2[i]] = i;
        }
        sort(arr1.begin(), arr1.end(), [&m](int x, int y){
            auto iter_x = m.find(x);
            auto iter_y = m.find(y);
            if (iter_x == m.end() && iter_y == m.end()) {
                return x < y;
            }
            if (iter_x == m.end()) {
                return false;
            }
            if (iter_y == m.end()) {
                return true;
            }
            return iter_x->second < iter_y->second;
        });
        return arr1;
    }
};
int main(int argc, const char * argv[]) {
    vector<int>arr1 = {28,6,22,8,44,17};
    vector<int>arr2 = {22,28,8,6};
    Solution s;
    s.relativeSortArray(arr1, arr2);
    return 0;
}
