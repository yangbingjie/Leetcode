//
//  main.cpp
//  5_longestPalindrome
//
//  Created by Bella Yang on 2019/8/3.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
private:
    int start;
    int end;
    int len;
    
public:
    Solution(){
        this->start = 0;
        this->end = -1;
        this->len = -1;
    }
    void findSubString(int center, string s, int offset){
        int i;
        int j;
        for (i = center - 1, j = center + offset; i >= 0 && j < s.length();--i, ++j) {
            if (s[i] != s[j]) {
                break;
            }
        }
        i++;
        j--;
        if ((j - i + 1) > this->len) {
            this->start = i;
            this->end = j;
            this->len = j - i + 1;
        }
    }
    
    string longestPalindrome(string s) {
        if (s.length() == 0) {
            return "";
        }
        if (s.length() == 1) {
            return s;
        }
        
        for (int center = 0; center < s.length(); ++center) {
            if (s[center] == s[center + 1]) {
                this->findSubString(center, s, 2);
            }
            this->findSubString(center, s, 1);
        }
        
        return s.substr(start, len);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    cout << s.longestPalindrome("abbb")<<endl;
    return 0;
}
