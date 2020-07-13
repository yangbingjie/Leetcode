//
//  main.cpp
//  804_uniqueMorseRepresentations
//
//  Created by bella on 2020/7/13.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        const string morse[26] = {".-","-...","-.-.","-..",".","..-.",
            "--.","....","..",".---","-.-",".-..",
            "--","-.","---",".--.","--.-",".-.","...",
            "-","..-","...-",".--","-..-","-.--","--.."};
        set<string>::iterator iter;
        set<string>s;
        string str;
        for (int i = 0; i < words.size(); ++i) {
            str = "";
            for (int j = 0; j < words[i].size(); ++j) {
                str += morse[words[i][j] - 'a'];
            }
            iter = s.find(str);
            if (iter == s.end()) {
                s.insert(str);
            }
        }
        return s.size();
    }
};
int main(int argc, const char * argv[]) {
    const int LEN = 4;
    string arr[LEN] = {"gin", "zen", "gig", "msg"};
    vector<string>words(arr, arr + LEN);
    Solution s;
    cout << s.uniqueMorseRepresentations(words) << endl;
    return 0;
}
