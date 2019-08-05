//
//  main.cpp
//  9_isPalindrome
//
//  Created by Bella Yang on 2019/8/5.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        bool result = false;
        string str;
        stringstream s;
        s << x;
        s >> str;
        
        for (int i = 0, j = int(str.length() - 1); i < j; ++i, --j) {
            if (str[i] != str[j]) {
                return result;
            }
        }
        result = true;
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    cout << s.isPalindrome(1223221) << endl;
    return 0;
}
