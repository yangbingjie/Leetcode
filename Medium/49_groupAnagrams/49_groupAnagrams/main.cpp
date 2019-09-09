//
//  main.cpp
//  49_groupAnagrams
//
//  Created by Bella Yang on 2019/9/9.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iterator>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        if (strs.empty()) {
            return result;
        }
        multimap<string, string> strMap;
        string tmp;
        for (int i = 0; i < strs.size(); ++i) {
            tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            strMap.insert(pair<string, string>(tmp, strs[i]));
        }
        multimap<string, string>::iterator i = strMap.begin();
        tmp = i->first;
        result.push_back(vector<string>(1, i->second));
        i++;
        while (i != strMap.end()) {
            if (tmp != i->first) {
                result.push_back(vector<string>(1, i->second));
                tmp = i->first;
            }else{
                result[result.size() - 1].push_back(i->second);
            }
            i++;
        }
        return result;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    const int LEN = 6;
    string array[LEN] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<string>strs(array, array + LEN);
    s.groupAnagrams(strs);
    return 0;
}
