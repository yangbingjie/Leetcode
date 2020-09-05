//
//  main.cpp
//  60_getPermutation
//
//  Created by bella on 2020/9/5.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;
class Solution {
public:
    string getPermutation(int n, int k) {
        if (n == 1) {
            return "1";
        }
        list<int> li;
        int factorial = 1;
        for (int i = 1; i < n; ++i) {
            factorial *= i;
            li.insert(li.end(), i);
        }
         li.insert(li.end(), n);
        string str = "";
        int ind = 0;
        list<int>::iterator iter = li.begin();
        --k;
        for (int i = n - 1; k != 0; --i) {
            ind = k / factorial;
            k = k - ind * factorial;
            factorial /= i;
            iter = li.begin();
            while (ind > 0) {
                ind--;
                iter++;
            }
            str += *iter + '0';
            li.erase(iter);
        }
        iter = li.begin();
        while (iter != li.end()) {
            str+= *iter + '0';
            iter++;
        }
        return str;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.getPermutation(9, 111) << endl;
    return 0;
}
