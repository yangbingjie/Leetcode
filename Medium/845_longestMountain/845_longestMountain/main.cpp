//
//  main.cpp
//  845_longestMountain
//
//  Created by Bella Yang on 2020/10/25.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int longestMountain(vector<int>& A) {
        vector<int> inc(A.size(), 0);
        for (int i = 1; i < inc.size(); ++i) {
            if (A[i] > A[i - 1]) {
                inc[i] = inc[i - 1] + 1;
            }
        }
        vector<int> dec(A.size(), 0);
        for (int i = dec.size() - 2; i >= 0; --i) {
            if (A[i] > A[i + 1]) {
                dec[i] = dec[i + 1] + 1;
            }
        }
        int longest = 1;
        int tmp;
        for (int i = 0; i < A.size(); ++i) {
            tmp = inc[i] + dec[i];
            if (longest < tmp) {
                longest = tmp;
            }
        }
        return longest > 1 ? longest + 1 : 0;
    }
};
int main(int argc, const char * argv[]) {
    vector<int> a = {1,2,2};
    Solution s;
    cout << s.longestMountain(a) << endl;
    return 0;
}
