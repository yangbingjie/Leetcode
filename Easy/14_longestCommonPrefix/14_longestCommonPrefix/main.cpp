//
//  main.cpp
//  14_longestCommonPrefix
//
//  Created by Bella Yang on 2019/8/6.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {
            return "";
        }
        if (strs.size() == 1) {
            return strs[0];
        }
        int index = 0;
        string result = "";
        bool match = true;
        while (match) {
            for (int i = 0; i < strs.size(); ++i) {
                if (index >= strs[i].size() || strs[i][index] != strs[0][index]) {
                    match = false;
                }
            }
            if (match) {
                result += strs[0][index];
                index++;
            }else{
                break;
            }
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    const int LEN = 2;
    string array[LEN] = {"abca","abc"};
    vector<string>strs(array, array + LEN);
    cout << s.longestCommonPrefix(strs) << endl;
    return 0;
}
