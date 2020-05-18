//
//  main.cpp
//  914_hasGroupsSizeX
//
//  Created by Bella Yang on 2020/5/18.
//  Copyright © 2020 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        if (deck.size() <= 1) {
            return false;
        }
        map<int, int>m;
        map<int, int>::iterator iter;
        for (int i = 0; i < deck.size(); ++i) {
            iter = m.find(deck[i]);
            if (iter != m.end()) {
                iter->second++;
            }else{
                m[deck[i]] = 1;
            }
        }
        iter = m.begin();
        int min_count = iter->second;
        while (iter != m.end()) {
            if (min_count > iter->second) {
                min_count = iter->second;
            }
            iter++;
        }
        for (int X = 2; X <= min_count ; X++) {
            iter = m.begin();
            while (iter!=m.end()) {
                if (iter->second % X != 0) {
                    break;
                }
                iter++;
            }
            if (iter == m.end()) {
                return true;
            }
        }
        return false;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    const int LEN = 8;
    int arr[LEN] = {1,1,1,2,2,2,3,3};
    vector<int>vec(arr, arr + LEN);
    cout << s.hasGroupsSizeX(vec) << endl;
    return 0;
}
