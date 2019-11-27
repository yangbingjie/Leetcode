//
//  main.cpp
//  392_isSubsequence
//
//  Created by Bella Yang on 2019/11/27.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool isSubsequence(string s, string t) {
        vector<vector<int> >vec(26);
        int index;
        for(int i = 0; i < t.size(); ++i){
            index = t[i] - 'a';
            vec[index].push_back(i);
        }
        int last_index = -1;
        bool find_index = false;
        int mid;
        int start;
        int end;
        for (int i = 0; i < s.size(); ++i) {
            index = s[i] - 'a';
            find_index = false;
            start = 0;
            end = int(vec[index].size());
            while (start != end) {
                mid = (end - start) / 2 + start;
                if (vec[index][mid] > last_index) {
                    find_index = true;
                    last_index = vec[index][mid];
                    break;
                }
            }
            if (!find_index) {
                return false;
            }
        }
        return true;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.isSubsequence("acb", "ahbgdc") << endl;
    return 0;
}
