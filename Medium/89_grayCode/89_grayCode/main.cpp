//
//  main.cpp
//  89_grayCode
//
//  Created by Bella Yang on 2019/9/18.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <bitset>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        result.push_back(0);
        if (n == 0) {
            return result;
        }
        int len = 1 << n;
        const int size = sizeof(int);
        bitset<size> value;
        
        for (int i = 1, j = 0; i < len; ++i) {
            if (i % 2 != 0) {
                value[0] = value[0] == false ? true : false;
            }else{
                j = 0;
                while (value[j] == false) {
                    j++;
                }
                value[j + 1] = value[j + 1]== false ? true : false;
            }
            cout<< value<<endl;
            result.push_back(int(value.to_ulong()));
        }
        return result;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    s.grayCode(3);
    return 0;
}
