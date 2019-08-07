//
//  main.cpp
//  17_letterCombinations
//
//  Created by Bella Yang on 2019/8/7.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        string telephone[8][4] = {
            {"a", "b", "c"},
            {"d", "e", "f"},
            {"g", "h", "i"},
            {"j", "k", "l"},
            {"m", "n", "o"},
            {"p", "q", "r", "s"},
            {"t", "u", "v"},
            {"w", "x", "y", "z"},
        };
        if (digits.size() <= 0) {
            return result;
        }
        int index = 0;
        while (digits[index] == '1') {
            index++;
        }
        int num = digits[index] - '0' - 2;
        int len = (num != 5 && num != 7) ? 3 : 4;
        for (int i = 0; i < len; ++i) {
            result.push_back(telephone[num][i]);
        }
        index++;
        int size;
        for (; index < digits.length(); ++index) {
            if (digits[index] == '1') {
                continue;
            }
            num = digits[index] - '0' - 2;
            len = (num != 5 && num != 7) ? 3 : 4;
            size = int(result.size());
            for (int i = 0; i < size; ++i) {
                for (int j = 1; j < len; ++j) {
                    result.push_back(result[i] + telephone[num][j]);
                }
                result[i] += telephone[num][0];
            }
            
        }
        
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<string> vec = s.letterCombinations("111123");
    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i] << " ";
    }
    cout << endl;
    return 0;
}
