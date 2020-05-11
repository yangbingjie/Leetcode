//
//  main.cpp
//  819_mostCommonWord
//
//  Created by Bella Yang on 2020/5/11.
//  Copyright © 2020 Bella Yang. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
class Solution {
public:
    string to_lower_str(string str){
        for (int i = 0; i < str.size(); ++i) {
            if (str[i] < 'a') {
                str[i] += 'a' - 'A';
            }
        }
        return str;
    }
    string mostCommonWord(string paragraph, vector<string>& banned) {
        map<string, int> m;
        int start = 0;
        string lower_str;
        int i = 0;
        while (i < paragraph.size() && !isalpha(paragraph[i])) {
            ++i;
        }
        start = i;
        for (; i < paragraph.size(); ++i) {
            if (isalpha(paragraph[i])){
                continue;
            }
            else{
                lower_str = to_lower_str(paragraph.substr(start, i - start));
                if (banned.end() == find(banned.begin(), banned.end(), lower_str)) {
                    if (m.end() == m.find(lower_str)) {
                        m[lower_str] = 1;
                    }else{
                        m[lower_str]++;
                    }
                }
            }
            while (i+1 < paragraph.size() && !isalpha(paragraph[i + 1])) {
                ++i;
            }
            start = ++i;
        }
        lower_str = to_lower_str(paragraph.substr(start, i - start));
        if (lower_str != "" && banned.end() == find(banned.begin(), banned.end(), lower_str)) {
            if (m.end() == m.find(lower_str)) {
                m[lower_str] = 1;
            }else{
                m[lower_str]++;
            }
        }
        int max_count = 0;
        string str;
        map<string, int>::iterator iter = m.begin();
        while (iter != m.end()) {
            if (iter->second > max_count) {
                str = iter->first;
                max_count = iter->second;
            }
            iter++;
        }
        return str;
    }
};
int main(int argc, const char * argv[]) {
    vector<string> vec;
    vec.push_back("hit");
    Solution s;
    cout << s.mostCommonWord("a.", vec) << endl;
    return 0;
}
