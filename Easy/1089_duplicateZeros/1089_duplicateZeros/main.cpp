//
//  main.cpp
//  1089_duplicateZeros
//
//  Created by Bella Yang on 2020/1/15.
//  Copyright © 2020 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int i = 0;
        int j = 0;
        while(j < arr.size()){
            if(arr[i] == 0){
                j++;
            }
            i++;
            j++;
        }
        j--;
        i--;

        while (i >= 0) {
            // cout<<i<<' '<<j<<endl;
            if (j < arr.size()) {
                arr[j] = arr[i];
            }
            if(arr[i] == 0){
                arr[--j] = 0;
            }
            j--;
            i--;
        }
        return;
    }
};
int main(int argc, const char * argv[]) {
//    const int LEN = 8;
//    int array[LEN] = {1,0,2,3,0,4,5,0};
//    const int LEN = 3;
//    int array[LEN] = {1,2,3};
//    const int LEN = 3;
//    int array[LEN] = {0,0,0};
    const int LEN = 8;
    int array[LEN] = {0,1,7,6,0,2,0,7};
    vector<int> vec(array, array + LEN);
    Solution s;
    s.duplicateZeros(vec);
    return 0;
}
