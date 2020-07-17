//
//  main.cpp
//  784_letterCasePermutation
//
//  Created by bella on 2020/7/17.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    char changeCase(char ch){
        if (ch > 'Z') {
            return ch - ('a' - 'A');
        }else{
            return ch + ('a' - 'A');
        }
    }
    vector<string> letterCasePermutation(string S) {
        vector<string>vec;
        if (S.size() == 0) {
            return vec;
        }
        string str = "";
        int size;
        if (isalpha(S[0])) {
            vec.push_back(str + S[0]);
            vec.push_back(str + changeCase(S[0]));
        }else{
            vec.push_back(str + S[0]);
        }
        
        for (int i = 1; i < S.size(); ++i) {
            size = vec.size();
            if (isalpha(S[i])) {
                for (int j = 0; j < size; ++j) {
                    vec.push_back(vec[j]);
                }
                for (int j = 0; j < vec.size(); ++j) {
                    if (j >= vec.size() / 2) {
                         vec[j] += S[i];
                    }else{
                        vec[j] += changeCase(S[i]);
                    }
                }
            }else{
                for (int j = 0; j < vec.size(); ++j) {
                    vec[j] += S[i];
                }

            }
        }
        return vec;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    s.letterCasePermutation("3z4");
    return 0;
}
