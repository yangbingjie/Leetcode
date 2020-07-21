//
//  main.cpp
//  01.06_compressString
//
//  Created by bella on 2020/7/21.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string compressString(string S) {
        if (S.size() <= 1) {
            return S;
        }
        string com_s = "";
        int fast = 1;
        int slow = 0;
        while (fast <= S.size()) {
            if (S[fast] == S[slow]) {
                fast++;
            }else{
                com_s += S[slow] + to_string(fast - slow);
                slow = fast;
                fast++;
            }
        }
        return com_s.size() < S.size() ? com_s : S;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.compressString("aabcccccaaa") << endl;
    cout << s.compressString("abbccd") << endl;
    cout << s.compressString("bb") << endl;
    return 0;
}
