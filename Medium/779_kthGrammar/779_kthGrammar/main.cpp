//
//  main.cpp
//  779_kthGrammar
//
//  Created by Bella Yang on 2020/1/7.
//  Copyright © 2020 Bella Yang. All rights reserved.
//

#include <iostream>
using namespace std;
class Solution {
public:
    int kthGrammar(int N, int K) {
        if(N == 1){
            return 0;
        }
        return (~K & 1) ^ kthGrammar(N - 1, (K + 1) / 2);
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.kthGrammar(4, 6) << endl;
    return 0;
}
