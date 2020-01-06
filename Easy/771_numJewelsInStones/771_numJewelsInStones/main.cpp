//
//  main.cpp
//  771_numJewelsInStones
//
//  Created by Bella Yang on 2020/1/6.
//  Copyright © 2020 Bella Yang. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int num = 0;
        sort(J.begin(), J.end());
        sort(S.begin(), S.end());
        for (int i = 0, j = 0; i < J.size() && j < S.size(); ) {
            if(J[i] < S[j]){
                i++;
                continue;
            }
            if (J[i] == S[j]){
                num++;
            }
            j++;
        }
        return num;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.numJewelsInStones("aA", "aAAbbbb") << endl;
    return 0;
}
