//
//  main.cpp
//  861_matrixScore
//
//  Created by Bella Yang on 2020/12/7.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        for (int i = 0; i < A.size(); ++i) {
            if (A[i][0] == 0) {
                for (int j = 0; j < A[0].size(); ++j) {
                    A[i][j] = (A[i][j] == 1 ? 0 : 1);
                }
            }
        }
        int count;
        for (int j = 1; j < A[0].size(); ++j) {
            count = 0;
            for (int i = 0; i < A.size(); ++i) {
                count += A[i][j];
            }
            if (count <= (A.size() - 1) / 2) {
                for (int i = 0; i < A.size(); ++i) {
                    A[i][j] = (A[i][j] == 1 ? 0 : 1);
                }
            }
        }
        int score = 0;
        int val;
        for (int i = 0; i < A.size(); ++i) {
            val = 0;
            for (int j = 0; j < A[0].size(); ++j) {
                val <<= 1;
                if (A[i][j] == 1) {
                    val++;
                }
            }
            score += val;
        }
        return score;
    }
};
int main(int argc, const char * argv[]) {
    vector<vector<int>> A = {{0,0,1,1},{1,0,1,0},{1,1,0,0}};
    Solution s;
    cout << s.matrixScore(A) << endl;
    return 0;
}
