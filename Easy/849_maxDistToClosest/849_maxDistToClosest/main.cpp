//
//  main.cpp
//  849_maxDistToClosest
//
//  Created by bella on 2020/7/17.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int slow = 0, fast = 0;
        int max_dist = 0;
        while (fast < seats.size() && seats[fast] == 0) {
            fast++;
        }
        if (max_dist < fast - slow) {
            max_dist = fast - slow;
        }
        int cur_dist;
        while(fast < seats.size()){
            if(seats[fast] == 0){
                fast++;
            }else{
                cur_dist = (fast - slow + 1) / 2;
                if(max_dist < cur_dist){
                    max_dist = cur_dist;
                }
                fast++;
                slow = fast;
            }
        }
        if (max_dist < fast - slow) {
            max_dist = fast - slow;
        }
        return max_dist;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    const int LEN = 5;
    int arr[LEN] = { 1,0,0,0,1};
    vector<int>vec(arr, arr + LEN);
    cout << s.maxDistToClosest(vec) << endl;
    return 0;
}
