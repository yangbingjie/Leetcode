//
//  main.cpp
//  Offer20_isNumber
//
//  Created by bella on 2020/9/2.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    bool isNumber(string s) {
        bool is_sign = true;
        bool need_more = true;
        int point_num = 0;
        int e_num = 0;
        bool has_num = false;
        s.erase(0,s.find_first_not_of(" "));
        s.erase(s.find_last_not_of(" ") + 1);
        for (int i = 0; i < s.size(); ++i) {
            if (isdigit(s[i])) {
                need_more = false;
                has_num = true;
                is_sign = false;
            }else if(s[i] == '.'){
                point_num++;
                is_sign = false;
                if (point_num > 1) {
                    return false;
                }
            }else if (s[i] == 'E' || s[i] == 'e'){
                e_num++;
                if (!has_num || e_num > 1) {
                    return false;
                }
                is_sign = true;
                point_num = 1;
                need_more = true;
            }else if(s[i] == '+' || s[i] == '-'){
                if (is_sign) {
                    is_sign = false;
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }
        return !need_more;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.isNumber("6ee69") << endl;
    return 0;
}
