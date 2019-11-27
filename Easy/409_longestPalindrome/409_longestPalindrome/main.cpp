//
//  main.cpp
//  409_longestPalindrome
//
//  Created by Bella Yang on 2019/11/27.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int>m;
        map<char, int>::iterator iter;
        for(int i = 0; i < s.size(); ++i){
            iter = m.find(s[i]);
            if(iter != m.end()){
                iter->second++;
            }else{
                m[s[i]] = 1;
            }
        }
        iter = m.begin();
        int len = 0;
        bool middle = false;
        while(iter != m.end()){
            if(iter->second % 2 == 0){
                len += iter->second;
            }else{
                len += iter->second - 1;
                middle = true;
            }
            iter++;
        }
        return len + middle;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.longestPalindrome("abbba") << endl;
    return 0;
}
