//
//  main.cpp
//  767_reorganizeString
//
//  Created by Bella Yang on 2020/11/30.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    string reorganizeString(string S) {
        vector<int>vec(26, 0);
        int max_count = 0;
        for (int i = 0; i < S.size(); ++i) {
            vec[S[i] - 'a']++;
            max_count = max(max_count, vec[S[i] - 'a']);
        }
        if (max_count > (S.size() + 1) / 2) {
           return "";
       }
        string result(S.size(), '#');
        int odd = 1;
        int even = 0;
        for (int i = 0; i < 26; ++i) {
            while (vec[i] > 0 && vec[i] <= S.size() / 2 && odd < S.size()) {
                result[odd] = 'a' + i;
                vec[i]--;
                odd += 2;
            }
            while (vec[i] > 0) {
                result[even] = 'a' + i;
                vec[i]--;
                even += 2;
            }
        }
        return result;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.reorganizeString("aaab") << endl;
    return 0;
}
