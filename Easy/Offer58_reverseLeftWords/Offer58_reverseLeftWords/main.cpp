//
//  main.cpp
//  Offer58_reverseLeftWords
//
//  Created by bella on 2020/7/21.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        n = n % s.size();
        return s.substr(n, s.size() - n) + s.substr(0, n);
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.reverseLeftWords("abcdefg", 2) << endl;
    cout << s.reverseLeftWords("lrloseumgh", 6) << endl;
    return 0;
}
