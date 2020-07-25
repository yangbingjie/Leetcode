//
//  main.cpp
//  884_uncommonFromSentences
//
//  Created by bella on 2020/7/25.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    void getWords(string str, map<string,int>&m, map<string, int>::iterator iter){
        int slow = 0;
        int fast = 0;
        string word;
        while (fast < str.size() && slow < str.size()) {
            while (slow < str.size() && str[slow] == ' ') {
                slow++;
            }
            while (fast < str.size() && str[fast] != ' ') {
                fast++;
            }
            word = str.substr(slow, fast - slow);
            iter = m.find(word);
            if (iter != m.end()) {
                iter->second++;
            }else{
                m[word] = 1;
            }
            fast++;
            slow = fast;
        }
    }
    vector<string> uncommonFromSentences(string A, string B) {
        vector<string>result;
        map<string, int> m;
        map<string, int>::iterator iter;
        getWords(A, m, iter);
        getWords(B, m, iter);
        iter = m.begin();
        while (iter != m.end()) {
            if (iter->second == 1) {
                result.push_back(iter->first);
            }
            iter++;
        }
        return result;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    s.uncommonFromSentences("this apple is sweet", "this apple is sour");
    return 0;
}
