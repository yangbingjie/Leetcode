//
//  main.cpp
//  1394_findLucky
//
//  Created by bella on 2020/7/24.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int, int>m;
        map<int, int>::iterator iter;
        for (int i = 0; i < arr.size(); ++i) {
            iter = m.find(arr[i]);
            if (iter != m.end()) {
                iter->second++;
            }else{
                m[arr[i]] = 1;
            }
        }
        int max_count = -1;
        iter = m.begin();
        while (iter != m.end()) {
            if (iter->second == iter->first && iter->first > max_count) {
                max_count = iter->first;
            }
            iter++;
        }
        return max_count;
    }
};
int main(int argc, const char * argv[]) {
    const int LEN = 5;
    int arr[LEN] = {2,2,2,3,3};
    vector<int>vec(arr, arr + LEN);
    Solution s;
    cout << s.findLucky(vec) << endl;
    return 0;
}
