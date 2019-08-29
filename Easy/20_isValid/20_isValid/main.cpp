//
//  main.cpp
//  20_isValid
//
//  Created by Bella Yang on 2019/8/29.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isLeft(char ch){
        return ch == '{' || ch == '(' || ch == '[';
    }
    bool isMatch(char left, char right){
        return (left == '{' && right == '}') || (left == '(' && right == ')') || (left == '[' && right == ']');
    }
    bool isValid(string s) {
        stack<char>sta;
        for (int i = 0; i < s.length(); ++i) {
            if (isLeft(s[i])) {
                sta.push(s[i]);
                continue;
            }
            if (!sta.empty() && isMatch(sta.top(), s[i])) {
                sta.pop();
            }else{
                return false;
            }
        }
        return sta.empty();
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    std::cout << s.isValid("]");
    return 0;
}
