//
//  main.cpp
//  44_isMatch
//
//  Created by bella on 2020/7/5.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> vec(s.size() + 1, vector<bool>(p.size() + 1, false));
        vec[0][0] = true;
        for (int j = 0; j < p.size(); ++j) {
            if (p[j] == '*') {
                vec[0][j + 1] = true;
            }else{
                break;
            }
        }
        for (int i = 0; i < s.size(); ++i) {
            for (int j = 0; j < p.size(); ++j) {
                if (s[i] == p[j] || p[j] == '?') {
                    vec[i + 1][j + 1] = vec[i][j];
                }else if (p[j] == '*'){
                    vec[i + 1][j + 1] = vec[i + 1][j] | vec[i][j + 1];
                }
            }            
        }
        return vec[s.size()][p.size()];
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.isMatch("baaaba","?*?***") << endl;
    return 0;
}
