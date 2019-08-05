//
//  main.cpp
//  6_convert
//
//  Created by Bella Yang on 2019/8/4.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        string result = "";
        int group_size = numRows + numRows - 2;
        if (group_size == 0) {
            return s;
        }
        int group_sum = ceil(double(s.length()) / double(group_size));
        // i 代表第i行
        for (int i = 0; i < numRows; ++i) {
            // j 代表第j组
            for (int j = 0; j < group_sum && i + j * group_size < s.length(); ++j) {
                // first 表示每组第一个元素的索引
                int first = i + j * group_size;
                result += s[first];
                // 第一行和最后一行一定没有第二个元素
                if (i == 0 || i == numRows - 1) {
                    continue;
                }
                // second 表示每组第二个元素的索引
                int second = first + group_size - 2 * i;
                // 当第二个元素超出时也不存在第二个元素
                if (second < s.length()) {
                    result += s[second];
                }
            }
        }
        
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    cout << s.convert("ABC", 2) << endl;
    return 0;
}
