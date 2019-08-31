//
//  main.cpp
//  22_generateParenthesis
//
//  Created by Bella Yang on 2019/8/30.
//  Copyright © 2019 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> vec;
        if (n == 0) {
            vec.push_back("");
            return vec;
        }
        vector<int> insert_index;
        vec.push_back("()");
        insert_index.push_back(1);
        int index = 0;
        int end;
        for (int i = 1; i < n; ++i) {
            end = int(vec.size());
            while (index < end) {
                for (int k = insert_index[index]; k <= vec[index].length(); ++k) {
                    vec.push_back(vec[index].substr(0, k) + "()" + vec[index].substr(k));
                    insert_index.push_back(k + 1);
                }
                index++;
            }
        }
        
        return vector<string>(vec.begin()+index, vec.end());
    }
};



int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    vector<string> v=s.generateParenthesis(4);
    return 0;
}
