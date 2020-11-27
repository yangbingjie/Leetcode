//
//  main.cpp
//  454_fourSumCount
//
//  Created by Bella Yang on 2020/11/27.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int>ab;
        unordered_map<int, int>cd;
        auto iter_1 = ab.begin();
        auto iter_2 = cd.begin();
        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j < C.size(); ++j) {
                iter_1 = ab.find(A[i] + B[j]);
                if (iter_1 == ab.end()) {
                    ab[A[i] + B[j]] = 1;
                }else{
                    iter_1->second++;
                }
                iter_2 = cd.find(C[i] + D[j]);
                if (iter_2 == cd.end()) {
                    cd[C[i] + D[j]] = 1;
                }else{
                    iter_2->second++;
                }
            }
        }
        iter_1 = ab.begin();
        iter_2 = cd.end();
        int count = 0;
        while (iter_1 != ab.end()) {
            iter_2 = cd.find(-iter_1->first);
            if (iter_2 != cd.end()) {
                count += iter_1->second * iter_2->second;
            }
            iter_1++;
        }
        return count;
    }
};
int main(int argc, const char * argv[]) {
    vector<int>A = {1,2};
    vector<int>B = {-2,-1};
    vector<int>C = {-1,2};
    vector<int>D = {0,2};
    Solution s;
    cout << s.fourSumCount(A, B, C, D) << endl;
    return 0;
}
