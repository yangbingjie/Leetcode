//
//  main.cpp
//  171_titleToNumber
//
//  Created by Bella Yang on 2019/10/23.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int titleToNumber(string s) {
        int num = 0;
        long factor = 1;
        for (int i = 0; i < s.size(); ++i) {
            num += (int(s[s.size() - 1 - i]) - 64) * factor;
            factor *= 26;
        }
        return num;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.titleToNumber("CFDGSXM");
    return 0;
}
