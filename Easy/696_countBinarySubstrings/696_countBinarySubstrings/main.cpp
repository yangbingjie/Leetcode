//
//  main.cpp
//  696_countBinarySubstrings
//
//  Created by bella on 2020/8/10.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int countBinarySubstrings(string s) {
        int count[2] = {0, 0};
        int result = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '0') {
                count[0]++;
            }else{
                count[1]++;
            }
            if (i == s.size() || s[i] != s[i + 1]) {
                result += min(count[0], count[1]);
                if (s[i + 1] == '0') {
                    count[0] = 0;
                }else{
                    count[1] = 0;
                }
            }
        }
        return result;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.countBinarySubstrings("00011")<<endl;
    return 0;
}
