//
//  main.cpp
//  242_isAnagram
//
//  Created by Bella Yang on 2019/11/22.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
#include <iterator>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        map<char, int> m;
        for (int i = 0; i < s.size(); ++i) {
            m[s[i]]++;
            m[t[i]]--;
        }
        map<char, int>::iterator iter = m.begin();
        while (iter != m.end()) {
            if (iter->second != 0) {
                return false;
            }
            iter++;
        }
        return true;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.isAnagram("a", "b") << endl;
    return 0;
}
