//
//  main.cpp
//  821_shortestToChar
//
//  Created by bella on 2020/7/17.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int>vec(S.size(), INT_MAX);
        int cur_dist = INT_MAX;
        for (int i = 0; i < S.size(); ++i) {
            if (S[i] == C) {
                vec[i] = 0;
                cur_dist = 0;
            }else{
                if (cur_dist != INT_MAX) {
                    cur_dist++;
                    vec[i] = cur_dist;
                }
            }
        }
        cur_dist = INT_MAX;
        for (int j = S.size() - 1; j >= 0; --j) {
            if (S[j] == C) {
                cur_dist = 0;
            }else{
                if (cur_dist != INT_MAX) {
                    cur_dist++;
                    vec[j] = min(vec[j], cur_dist);
                }
            }
        }
        return vec;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    s.shortestToChar("loveleetcode", 'e');
    return 0;
}
