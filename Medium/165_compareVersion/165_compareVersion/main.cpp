//
//  main.cpp
//  165_compareVersion
//
//  Created by Bella Yang on 2020/5/13.
//  Copyright © 2020 Bella Yang. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int start1 = 0;
        int end1 = 0;
        int start2 = 0;
        int end2 = 0;
        int v1;
        int v2;
        while (end1 < version1.size() || end2 < version2.size()) {
            while (end1 < version1.size() && version1[end1] != '.') {
                end1++;
            }
            while (end2 < version2.size() && version2[end2] != '.') {
                end2++;
            }
            v1 = end1 <= version1.size() ? stoi(version1.substr(start1, end1)) : 0;
            v2 = end2 <= version2.size()  ? stoi(version2.substr(start2, end2)) : 0;
            if(v1 > v2){
                return 1;
            }else if (v1 < v2){
                return -1;
            }
            if (end1 <= version1.size()) {
                start1 = end1 + 1;
                end1 = start1 + 1;
            }
            if (end2 <= version2.size()) {
                start2 = end2 + 1;
                end2 = start2 + 1;
            }
        }
        v1 = end1 <= version1.size() ? stoi(version1.substr(start1, end1)) : 0;
        v2 = end2 <= version2.size() ? stoi(version2.substr(start2, end2)) : 0;
        if(v1 > v2){
            return 1;
        }else if (v1 < v2){
            return -1;
        }
        return 0;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.compareVersion("1.0", "1.0.0") << endl;
    return 0;
}
