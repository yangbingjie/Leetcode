//
//  main.cpp
//  67_addBinary
//
//  Created by Bella Yang on 2019/9/8.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int i = int(a.length() - 1);
        int j = int(b.length() - 1);
        bool carry = false;
        int tmp;
        for (; i >=0 || j >= 0; --i, --j) {
            tmp = carry + (i >= 0 ? a[i] - 48 : 0) + (j >= 0 ? b[j] - 48 : 0);
            carry = tmp > 1;
            result = to_string(tmp % 2) + result;
        }
        if (carry) {
            result = "1" + result;
        }
        return result;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.addBinary("1010",
                        "1011") << endl;
    return 0;
}
