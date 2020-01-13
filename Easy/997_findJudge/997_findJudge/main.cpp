//
//  main.cpp
//  997_findJudge
//
//  Created by Bella Yang on 2020/1/13.
//  Copyright © 2020 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> is_judge(N, 0);
        for(int i = 0; i < trust.size(); ++i){
            if(is_judge[trust[i][0] - 1] != -1){
                is_judge[trust[i][0] - 1] = -1;
            }
            if (is_judge[trust[i][1] - 1] != -1) {
                is_judge[trust[i][1] - 1]++;
            }            
        }
        int judge = -1;
        bool flag = true;
        for(int i = 0; i < N; ++i){
            if(is_judge[i] == N - 1){
                if(flag){
                    flag = false;
                    judge = i + 1;
                }else{
                    judge = -1;
                    break;
                }
            }
        }
        return judge;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    const int M = 7;
    const int N = 2;
    int array[M][N] = {{1,2},{1,3},{2,1},{2,3},{1,4},{4,3},{4,1}};
    vector<vector<int>> trust;
    for (int i = 0; i < M; ++i) {
        trust.push_back(vector<int>(array[i], array[i] + N));
    }
    cout << s.findJudge(4, trust) << endl;
    return 0;
}
