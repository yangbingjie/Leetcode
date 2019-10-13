//
//  main.cpp
//  5222_balancedStringSplit
//
//  Created by Bella Yang on 2019/10/13.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int balancedStringSplit(string s) {
        int count = 0;
        int r_num = 0;
        int l_num = 0;
        for(int i = 0; i < s.size();++i){
            if(s[i] == 'L'){
                l_num++;
            }else{
                r_num++;
            }
            if(r_num == l_num){
                count++;
                r_num = 0;
                l_num = 0;
            }
        }
        return count;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    std::cout << s.balancedStringSplit("RLRRLLRLRL");
    return 0;
}
