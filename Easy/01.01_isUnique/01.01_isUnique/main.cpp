//
//  main.cpp
//  01.01_isUnique
//
//  Created by Bella Yang on 2020/5/9.
//  Copyright © 2020 Bella Yang. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    bool isUnique(string astr) {
        vector<bool>vec(256, 0);
        for(int i = 0; i < astr.size(); ++i){
            if(vec[int(astr[i])] == 1){
                return false;
            }else{
                vec[int(astr[i])] = 1;
            }
        }
        return true;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.isUnique("leetcode") << endl;
    return 0;
}
