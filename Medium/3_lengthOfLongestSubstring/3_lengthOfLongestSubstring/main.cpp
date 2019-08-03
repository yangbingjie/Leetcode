//
//  main.cpp
//  3_lengthOfLongestSubstring
//
//  Created by Bella Yang on 2019/8/2.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) {
            return 0;
        }
        int max = 1;
        int substring = 1;
        vector<char> vec;
        vector<char>::iterator it;
        vec.push_back(s[0]);
        for (int i = 1; i < s.length(); ++i) {
            it = find(vec.begin(), vec.end(),s[i]);
            substring++;
            if (it == vec.end()){
                if (max <= substring) {
                    max = substring;
                }
            }else{
                while (it != vec.begin()) {
                    vec.erase(it);
                    it--;
                    substring--;
                }
                substring--;
                vec.erase(it);
            }
            vec.push_back(s[i]);
        }
        return max;
    }
};


int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.lengthOfLongestSubstring("bhjk");
    return 0;
}
