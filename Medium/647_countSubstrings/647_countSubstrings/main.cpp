//
//  main.cpp
//  647_countSubstrings
//
//  Created by bella on 2020/8/19.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        for (int i = 0; i < s.size(); ++i) {
            count++;
            for (int j = i, k = i + 1; j >= 0 && k < s.size(); --j, ++k) {
                if (s[j] == s[k]) {
                    count++;
                }else{
                    break;
                }
            }
            for (int j = i - 1, k = i + 1; j >= 0 && k < s.size(); --j, ++k) {
                if (s[j] == s[k]) {
                    count++;
                }else{
                    break;
                }
            }
        }
        return count;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.countSubstrings("aaaa") << endl;
    return 0;
}
