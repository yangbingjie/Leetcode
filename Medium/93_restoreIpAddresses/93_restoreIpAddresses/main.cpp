//
//  main.cpp
//  93_restoreIpAddresses
//
//  Created by bella on 2020/8/9.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
private:
    vector<string>result;
    vector<int>segment;
public:
    void dfs(string& s, int num, int begin){
        if (num == 4) {
            if (begin == s.size()) {
                string str = to_string(segment[0]);
                for (int i = 1; i < 4; ++i) {
                    str += "." + to_string(segment[i]);
                }
                result.push_back(str);
            }
            return;
        }
        if (begin == s.size()) {
            return;
        }
        int ip = 0;
        for (int i = 1; begin + i <= s.size() && i < 4; ++i) {
            if (s[begin] == '0') {
               segment[num] = 0;
               dfs(s, num + 1, begin + 1);
               return;
            }else{
                ip = stoi(s.substr(begin, i));
                if (ip >= 0 && ip <= 255) {
                    segment[num] = ip;
                    dfs(s, num + 1, begin + i);
                }else{
                    break;
                }
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        segment.resize(4);
        dfs(s, 0, 0);
        return result;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    s.restoreIpAddresses("0000");
    return 0;
}
