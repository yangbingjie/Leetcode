//
//  main.cpp
//  567_checkInclusion
//
//  Created by Bella Yang on 2021/2/10.
//

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()){
            return false;
        }
        unordered_map<char, int>m;
        auto iter = m.begin();
        for (int i = 0; i < s1.size(); ++i) {
            iter = m.find(s1[i]);
            if (iter != m.end()) {
                iter->second--;
            }else{
                m[s1[i]] = -1;
            }
        }
        int slow = 0;
        int fast = 0;
        while (fast < s1.size()) {
            iter = m.find(s2[fast]);
            if (iter != m.end()) {
                iter->second++;
                if (iter->second == 0) {
                    m.erase(iter);
                }
            }else{
                m[s2[fast]] = 1;
            }
            fast++;
        }
        if (m.empty()) {
            return true;
        }
        while (fast < s2.size()) {
            iter = m.find(s2[slow]);
            if (iter != m.end()) {
                iter->second--;
                if (iter->second == 0) {
                    m.erase(iter);
                }
            }else{
                m[s2[slow]] = -1;
            }
            iter = m.find(s2[fast]);
            if (iter != m.end()) {
                iter->second++;
                if (iter->second == 0) {
                    m.erase(iter);
                }
            }else{
                m[s2[fast]] = 1;
            }
            if (m.empty()) {
                return true;
            }
            slow++;
            fast++;
        }
        return false;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.checkInclusion("abc",
                             "ccccbbbbaaaa") << endl;
    return 0;
}
