//
//  main.cpp
//  316_removeDuplicateLetters
//
//  Created by Bella Yang on 2020/12/20.
//

#include <iostream>
#include <string>
#include <stack>
#include <set>
#include <map>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> sta;
        set<char>st;
        st.insert(s[0]);
        sta.push(s[0]);
        string str(1, s[0]);
        
        map<char, int>m;
        for (int i = 0; i < s.size(); ++i) {
            m[s[i]] = i;
        }
        for (int i = 1; i < s.size(); ++i) {
            if (st.end() != st.find(s[i])) {
                continue;
            }
            while (!sta.empty() && s[i] < sta.top() && i < m[sta.top()]) {
                st.erase(sta.top());
                sta.pop();
                str = str.substr(0, str.size() - 1);
            }
            sta.push(s[i]);
            str += string(1, s[i]);
            st.insert(s[i]);
        }
        return str;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.removeDuplicateLetters("bbcaac") << endl;
    return 0;
}
