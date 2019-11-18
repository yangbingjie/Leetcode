//
//  main.cpp
//  205_isIsomorphic
//
//  Created by Bella Yang on 2019/11/18.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
using namespace std;


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        const int LEN = 208;
        char a[LEN] = {0};
        char b[LEN] = {0};
        for (int i = 0; i < s.length(); ++i) {
            if (a[s[i]] == 0) {
                if (b[t[i]] == 0) {
                    a[s[i]] = t[i];
                    b[t[i]] = s[i];
                }else{
                    return false;
                }
            }
            if (a[s[i]] != t[i]) {
                return false;
            }
        }
        return true;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.isIsomorphic("qwertyuiop[]asdfghjkl;'\\zxcvbnm,./","',.pyfgcrl/=aoeuidhtns-\\;qjkxbmwvz") << endl;
    return 0;
}
