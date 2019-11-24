//
//  main.cpp
//  345_reverseVowels
//
//  Created by Bella Yang on 2019/11/23.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <set>
#include <string>
using namespace std;
class Solution {
public:
    string reverseVowels(string s) {
        set<char> se;
        se.insert('a');
        se.insert('e');
        se.insert('i');
        se.insert('o');
        se.insert('u');
        se.insert('A');
        se.insert('E');
        se.insert('I');
        se.insert('O');
        se.insert('U');
        set<char>::iterator iter_1;
        set<char>::iterator iter_2;
        for (int i = 0, j = int(s.size() - 1); i < j;) {
            iter_1 = se.find(s[i]);
            iter_2 = se.find(s[j]);
            if (iter_1 != se.end() && iter_2 != se.end()) {
                swap(s[i], s[j]);
                i++;
                j--;
                continue;
            }
            if (iter_1 == se.end()){
                i++;
            }
            if (iter_2 == se.end()) {
                j--;
            }
        }
        return s;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.reverseVowels("aA") << endl;
    return 0;
}
