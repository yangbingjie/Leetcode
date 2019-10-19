//
//  main.cpp
//  168_convertToTitle
//
//  Created by Bella Yang on 2019/10/19.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <string>
#include <set>
#include <cmath>
using namespace std;
class Solution {
public:
    string convertToTitle(int n) {
        string str = "";
        const int LEN = 26;
        int index = 0;
        while (n > 0) {
            index = (n - 1) % LEN;
            n = int((n - 1) / LEN);
            str = char('A' + index) + str;
        }
        return str;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.convertToTitle(1) << endl;
    return 0;
}
