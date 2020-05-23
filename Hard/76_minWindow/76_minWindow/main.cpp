//
//  main.cpp
//  76_minWindow
//
//  Created by Bella Yang on 2020/5/23.
//  Copyright © 2020 Bella Yang. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
using namespace std;
class Solution {
public:
    bool check( int t_count[], int s_count[]){
        for (int i = 0; i < 256; ++i) {
            if (t_count[i] > s_count[i]) {
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        if (s == "" || t == ""|| s.size() < t.size()) {
            return "";
        }
        int t_count[256] = {0};
        for (int i = 0; i < t.size(); ++i) {
            t_count[t[i]]++;
        }
        int s_count[256] = {0};
        int min_len = int(s.size());
        int result_start = -1;
        int len = 0;
        int start = 0;
        
        while (start + len < s.size()) {
            while (start + len < s.size()) {
                s_count[s[start + len]]++;
                if (check(t_count, s_count)) {
                    if (min_len > len) {
                        result_start = start;
                        min_len = len;
                    }
                    break;
                }
                len++;
            }
            while (len >= t.size()) {
                s_count[s[start]]--;
                start++;
                len--;
                if (!check(t_count, s_count)) {
                    break;
                }
                if (min_len > len) {
                    result_start = start;
                    min_len = len;
                }
            }
            len++;
        }
        
        return result_start != -1 ? s.substr(result_start, min_len + 1) : "";
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.minWindow("a", "aa") << endl;
    return 0;
}
