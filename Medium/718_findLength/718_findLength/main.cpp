//
//  main.cpp
//  718_findLength
//
//  Created by Bella Yang on 2020/7/1.
//  Copyright © 2020 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        vector<vector<int> >vec(A.size() + 1, vector<int>(B.size() + 1, 0));
        int max_len = 0;
        for (int i = 1; i < vec.size(); ++i) {
            for (int j = 1; j < vec[0].size(); ++j) {
                if (A[i - 1] == B[j - 1]) {
                    vec[i][j] = vec[i - 1][j - 1] + 1;
                    if (max_len < vec[i][j]) {
                        max_len = vec[i][j];
                    }
                }
            }
        }
        return max_len;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    const int LEN1 = 5;
    const int LEN2 = 5;
    int arr1[LEN1] = {1,2,3,2,1};
    int arr2[LEN2] = {3,2,1,4,7};
    vector<int>A(arr1, arr1 + LEN1);
    vector<int>B(arr2, arr2 + LEN2);
    cout << s.findLength(A, B) << endl;
    return 0;
}
