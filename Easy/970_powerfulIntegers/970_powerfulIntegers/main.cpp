//
//  main.cpp
//  970_powerfulIntegers
//
//  Created by Bella Yang on 2020/1/9.
//  Copyright © 2020 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <set>
using namespace std;
class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        set<int>s;
        int powerful;
        int length = -1;
        for(int i = 0;length != s.size();++i){
            length = int(s.size());
            powerful = 0;
            for(int j = 0;powerful <= bound; ++j){
                powerful = pow(x, i) + pow(y, j);
                if(powerful <= bound){
                    s.insert(powerful);
                }
                if (y == 1) {
                    break;
                }
            }
        }
        return vector<int>(s.begin(), s.end());
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> v = s.powerfulIntegers(1, 2, 10);
    return 0;
}
