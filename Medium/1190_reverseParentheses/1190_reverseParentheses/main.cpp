//
//  main.cpp
//  1190_reverseParentheses
//
//  Created by Bella Yang on 2020/5/14.
//  Copyright © 2020 Bella Yang. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> sta;
        string tmp;
        string result = "";
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != ')') {
                sta.push(s[i]);
            }else{
                tmp = "";
                while (!sta.empty() && sta.top() != '(') {
                    tmp = tmp + sta.top();
                    sta.pop();
                }
                sta.pop();
                for (int j = 0; j < tmp.size(); ++j) {
                    sta.push(tmp[j]);
                }
            }
        }
        while (!sta.empty()) {
            result = sta.top() + result;
            sta.pop();
        }
        return result;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.reverseParentheses("a(bcdefghijkl(mno)p)q") << endl;
    return 0;
}
