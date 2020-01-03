//
//  main.cpp
//  1047_removeDuplicates
//
//  Created by Bella Yang on 2020/1/3.
//  Copyright © 2020 Bella Yang. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string removeDuplicates(string S) {
        bool is_updated = false;
        do{
            is_updated = false;
            for(int i = 0; i + 1 < S.size(); ++i){
                if(S[i] == S[i + 1]){
                    is_updated = true;
                    S = S.substr(0, i) + (i + 2 <= S.size() - 1 ? S.substr(i + 2, S.size()) : "");
                    i--;
                }
            }
        }while(is_updated);
        return S;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    std::cout << s.removeDuplicates("azxxzy");
    return 0;
}
