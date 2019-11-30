//
//  main.cpp
//  443_compress
//
//  Created by Bella Yang on 2019/11/29.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int index = 0;
        char ch = chars[0];
        int count = 1;
        vector<char> v;
        for (int i = 1; i < chars.size(); ++i) {
            if (ch != chars[i]) {
                chars[index] = ch;
                if (count > 1) {
                    index++;
                    v.clear();
                    while (count > 0) {
                        v.push_back('0' + count % 10);
                        count -= count % 10;
                        count /= 10;
                    }
                    for (int j = int(v.size() - 1); j >= 0; --j) {
                        chars[index] = v[j];
                        index++;
                    }
                }else{
                    index++;
                }
                ch = chars[i];
                count = 1;
            }else{
                count++;
            }
            
        }
        
        chars[index] = ch;
        if (count > 1) {
            index++;
            v.clear();
            while (count > 0) {
                v.push_back('0' + count % 10);
                count -= count % 10;
                count /= 10;
            }
            for (int j = int(v.size() - 1); j >= 0; --j) {
                chars[index] = v[j];
                index++;
            }
        }else{
            index++;
        }
        return index;
    }
};
int main(int argc, const char * argv[]) {
    const int LEN = 7;
    char array[LEN] = {'a','a','a','b','b','a','a'};
    vector<char>chars(array, array + LEN);
    Solution s;
    cout << s.compress(chars) << endl;
    return 0;
}
