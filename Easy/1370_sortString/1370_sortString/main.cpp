//
//  main.cpp
//  1370_sortString
//
//  Created by Bella Yang on 2020/11/25.
//

#include <iostream>
#include <map>
#include <string>
using namespace std;
class Solution {
public:
    string sortString(string s) {
        map<char, int>m;
        auto iter = m.begin();
        for (int i = 0; i < s.size(); ++i) {
            iter = m.find(s[i]);
            if (iter != m.end()) {
                iter->second++;
            }else{
                m[s[i]]++;
            }
        }
        string result;
        while (result.size() != s.size()) {
            iter = m.begin();
            while (iter != m.end()) {
                if (iter->second) {
                    result += string(1, iter->first);
                    iter->second--;
                }
                iter++;
            }
            iter = m.end();
            iter--;
            while (iter != m.begin()) {
                if (iter->second) {
                    result += string(1, iter->first);
                    iter->second--;
                }
                iter--;
            }
            if (iter->second) {
                result += string(1, iter->first);
                iter->second--;
            }
        }
        return result;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.sortString("spo") << endl;
    return 0;
}
