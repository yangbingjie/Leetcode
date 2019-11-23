//
//  main.cpp
//  290_wordPattern
//
//  Created by Bella Yang on 2019/11/23.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <map>
#include <string>
#include <iterator>
using namespace std;

class finder
{
public:
    finder(const string &cmp_string) :s_(cmp_string){}
    bool operator ()(const map<int, string>::value_type &item)
    {
        return item.second == s_;
    }
private:
    const string &s_;
};

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<char, string> m;
        string current = "";
        map<char, string>::iterator iter_1;
        map<char, string>::iterator iter_2;
        int j = 0;
        for (int i = 0; i <= str.size(); ++i) {
            if (i < str.size() && str[i] != ' ') {
                current += str[i];
            }else{
                if (current != "") {
                    iter_1 = m.find(pattern[j]);
                    iter_2 = find_if(m.begin(), m.end(), finder(current));
                    if ((iter_1 != m.end() && iter_1->second != current) ||  (iter_2 != m.end() && iter_2->first != pattern[j])) {
                        return false;
                    }else{
                        m[pattern[j]] = current;
                    }
                    j++;
                    current = "";
                }
            }
        }

        return j == pattern.size();
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.wordPattern("abba", "dog dog, dog dog") << endl;
    
    map<char, string> m;
    string current = "2";
    map<char, string>::iterator iter_2;
    m['b'] = "2";
    iter_2 = find_if(m.begin(), m.end(), finder(current));

    return 0;
}
