//
//  main.cpp
//  1417_reformat
//
//  Created by bella on 2020/7/24.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
using namespace std;
class Solution {
public:
    string reformat(string s) {
        if (s.size() <= 1) {
            return s;
        }
        int dig = 0;
        int alp = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (isalpha(s[i])) {
                alp++;
            }
        }
        dig = s.size() - alp;
        if (abs(alp - dig) >= 2) {
            return "";
        }
        bool dig_first = dig > alp;
        dig = 0;
        alp = 0;
        string str = "";
        while (str.size() != s.size()) {
            while (dig < s.size() && !isdigit(s[dig])) {
                dig++;
            }
            while (alp < s.size() && !isalpha(s[alp])) {
                alp++;
            }
            if (dig_first) {
                if (dig < s.size()) {
                    str += s[dig];
                }
                if (alp < s.size()){
                    str += s[alp];
                }
            }else{
                if (alp < s.size()) {
                    str += s[alp];
                }
                if (dig < s.size()){
                    str += s[dig];
                }
            }
            dig++;
            alp++;
        }
        return str;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.reformat("103ab") << endl;
    return 0;
}
