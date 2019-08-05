//
//  main.cpp
//  7_reverse
//
//  Created by Bella Yang on 2019/8/5.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        if (x == 0) {
            return 0;
        }
        // int转string
        stringstream s;
        string str;
        s << x;
        s >> str;
        string result_str;
        
        // 判断输入x的符号
        int end = 0;
        if (str[0] == '-') {
            result_str+="-";
            end = 1;
        }
        
        // 去掉输入x末尾的所有0
        int i = int(str.length() - 1);
        while (str[i] == '0') {
            i--;
        }
        
        // 倒序加入结果
        for (; i >= end ; --i) {
            result_str += str[i];
        }
        
        // string转int
        s.clear();
        long result_num;
        s << result_str;
        s >> result_num;
        
        // 判读是否溢出
        if (result_num < -2147483648 || result_num  > 2147483647) {
            result_num = 0;
        }
        
        return int(result_num);
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.reverse(0) << endl;
    return 0;
}
