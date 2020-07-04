//
//  main.cpp
//  32_longestValidParentheses
//
//  Created by bella on 2020/7/4.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.size() < 2) {
            return 0;
        }
        int result = 0;
        stack<int> sta;
        sta.push(-1);
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                sta.push(i);
            }else{
                sta.pop();
                if (sta.empty()) {
                    sta.push(i); // 当括号匹配光了，栈还需要留一个“垫底”的“参照物”
                }else{
                    result = max(result, i - sta.top());
                }
            }
        }
        return result;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.longestValidParentheses("()(()") << endl;
    return 0;
}
