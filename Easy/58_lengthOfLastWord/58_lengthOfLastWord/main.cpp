//
//  main.cpp
//  58_lengthOfLastWord
//
//  Created by Bella Yang on 2019/9/11.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        int i = int(s.length() - 1);
        while(i >= 0 && s[i] == ' '){
            i--;
        }
        for(; i >= 0; --i){
            if(s[i] != ' '){
                length++;
            }else{
                break;
            }
        }
        return length;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.lengthOfLastWord("Hello world") << endl;
    return 0;
}
