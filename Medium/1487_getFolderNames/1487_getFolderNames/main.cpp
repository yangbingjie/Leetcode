//
//  main.cpp
//  1487_getFolderNames
//
//  Created by Bella Yang on 2020/10/9.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        vector<string>new_names(names.size());
        map<string, int>m;
        auto iter = m.begin();
        auto str_iter = m.begin();
        string name;
        for (int i = 0; i < names.size(); ++i) {
            iter = m.find(names[i]);
            if (iter == m.end()) {
                m[names[i]] = 1;
                new_names[i] = names[i];
            }else{
                int j = iter->second;
                name = names[i] + '(' + to_string(j) + ')';
                str_iter = m.find(name);
                while (str_iter != m.end()) {
                    j++;
                    iter->second++;
                    name = names[i] + '(' + to_string(j) + ')';
                    str_iter = m.find(name);
                }
                new_names[i] = name;
                m[name] = 1;
            }
        }
        return new_names;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    vector<string>str = {"kaido","kaido(1)","kaido","kaido(1)"};
    s.getFolderNames(str);
    return 0;
}
