//
//  main.cpp
//  1025_divisorGame
//
//  Created by bella on 2020/7/24.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
using namespace std;
class Solution {
public:
    bool divisorGame(int N) {
        return N % 2 == 0;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.divisorGame(3) << endl;
    return 0;
}
