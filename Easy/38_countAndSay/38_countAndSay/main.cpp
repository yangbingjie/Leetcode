//
//  main.cpp
//  38_countAndSay
//
//  Created by Bella Yang on 2019/9/6.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string countAndSay(int n) {
        string model = "1";
        string result = model;
        int i = 1;
        int count;
        char lastNum;
        while (i < n) {
            count = 1;
            result.clear();
            lastNum = model[0];
            for (int i = 1; i < model.length(); ++i) {
                if (lastNum == model[i]) {
                    count++;
                }else{
                    result += to_string(count) + lastNum;
                    count = 1;
                    lastNum = model[i];
                }
            }
            result += to_string(count) + lastNum;
            model = result;
            i++;
        }
        return result;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.countAndSay(5) << endl;
    return 0;
}
