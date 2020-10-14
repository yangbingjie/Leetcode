//
//  main.cpp
//  Offer13_movingCount
//
//  Created by Bella Yang on 2020/10/14.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool check(int row, int col, int k){
        int sum = 0;
        while (row != 0) {
            sum += row % 10;
            row /= 10;
        }
        while (col != 0) {
            sum += col % 10;
            col /= 10;
        }
        return sum <= k;
    }
    int movingCount(int m, int n, int k) {
        if(k == 0){
            return 1;
        }
        int count = 1;
        vector<bool>rows(m, false);
        vector<bool>cols(n, false);
        for (int i = 1; i < m; ++i) {
            if (check(i, 0, k)) {
                count++;
                rows[i] = true;
            }else{
                break;
            }
        }
        for (int j = 1; j < n; ++j) {
            if (check(0, j, k)) {
                cols[j] = true;
                count++;
            }else{
                break;
            }
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if ((rows[i] || cols[j]) && check(i, j, k)) {
                    rows[i] = true;
                    cols[j] = true;
                    count++;
                }else{
                    rows[i] = false;
                    cols[j] = false;
                }
            }
        }
        return count;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.movingCount(82, 62, 6) << endl;
    return 0;
}
