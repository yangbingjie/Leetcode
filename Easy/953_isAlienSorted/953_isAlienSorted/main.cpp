//
//  main.cpp
//  953_isAlienSorted
//
//  Created by Bella Yang on 2020/1/17.
//  Copyright © 2020 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int arr[26];
        for(int i = 0; i < 26; ++i){
            arr[order[i] - 'a'] = i;
        }
        int j;
        bool flag;
        int a, b;
        for(int i = 0; i < words.size() - 1; ++i){
            flag = true;
            for(j = 0; j < words[i].size() && j < words[i + 1].size(); ++j){
                a = arr[words[i][j] - 'a'];
                b = arr[words[i + 1][j] - 'a'];
                if(a < b){
                    flag = false;
                    break;
                }else if(a > b){
                    return false;
                }
            }
            if(flag && words[i].size() > words[i + 1].size()){
                return false;
            }
        }
        return true;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    vector<string>v;
    v.push_back("apple");
    v.push_back("app");
    cout << s.isAlienSorted(v, "abcdefghijklmnopqrstuvwxyz") << endl;
    return 0;
}
