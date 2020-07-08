//
//  main.cpp
//  1233_removeSubfolders
//
//  Created by bella on 2020/7/8.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    bool isSubfolders(string folder, string subfolder){
        string subroot = "";
        for (int i = subfolder.size() - 1; i >= 0; --i) {
            if (subfolder[i] == '/') {
                subroot = subfolder.substr(0, i);
                break;
            }
        }
        if (subroot.size() < folder.size()) {
            return false;
        }
        for (int i = 0; i < folder.size(); ++i) {
            if (folder[i] != subroot[i]) {
                return false;
            }
        }
        return true;
    }
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string>result;
        sort(folder.begin(), folder.end());
        result.push_back(folder[0]);
        for (int i = 1; i < folder.size(); ++i) {
            if (!isSubfolders(result[result.size() - 1], folder[i])) {
                result.push_back(folder[i]);
            }
        }
        return result;
    }
};
int main(int argc, const char * argv[]) {
    const int LEN = 3;
//    string arr[LEN] = {"/c/f","/a/b","/c/d","/c/d/e","/a"};
//    string arr[LEN] = {"/a","/a/b/c","/a/b/d"};
    string arr[LEN] = {"/a/b/c","/a/b/d","/a/b/ca"};
    vector<string>folder(arr, arr + LEN);
    Solution s;
    s.removeSubfolders(folder);
    return 0;
}
