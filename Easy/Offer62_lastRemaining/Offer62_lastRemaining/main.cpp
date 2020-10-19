//
//  main.cpp
//  Offer62_lastRemaining
//
//  Created by Bella Yang on 2020/10/19.
//

#include <iostream>
using namespace std;
class Solution {
public:
    int lastRemaining(int n, int m) {
        long d = 1;
        while(d <= (long(m) - 1) * long(n)){
            d = ceil(double(m) * d / double(m - 1));
        }
        return long(n) * long(m) - d;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.lastRemaining(5, 3) << endl;
    return 0;
}
