//
//  main.cpp
//  1046_lastStoneWeight
//
//  Created by Bella Yang on 2020/1/19.
//  Copyright © 2020 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        vector<int>::iterator iter = stones.end();
        int index = stones.size() - 1;
        while(index > 0){
            sort(stones.begin(), iter);
            if(stones[index] == stones[index - 1]){
                index -= 2;
                iter--;
                iter--;
            }else{
                stones[index - 1] = stones[index] - stones[index - 1];
                index--;
                iter--;
            }
        }
        return index == 0 ? stones[0] : 0;
    }
};
int main(int argc, const char * argv[]) {
    const int LEN = 6;
    int arr[LEN] = {2,7,4,1,8,1};
    vector<int>vec(arr, arr + LEN);
    Solution s;
    cout <<s.lastStoneWeight(vec) << endl;
    return 0;
}
