//
//  main.cpp
//  406_reconstructQueue
//
//  Created by bella on 2020/7/3.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    static bool comp(vector<int> a, vector<int> b){
        if (a[0] < b[0]) {
            return false;
        }else if (a[0] > b[0]){
            return true;
        }else{
            return a[1] < b[1];
        }
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), comp);
        vector<vector<int>> new_people;
        for (int i = 0; i < people.size(); ++i) {
            new_people.insert(new_people.begin() + people[i][1], people[i]);
        }
        return new_people;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    const int LEN1 = 6;
    const int LEN2 = 2;
    int arr[LEN1][LEN2] = {{7,0}, {4,4}, {7,1}, {5,0}, {6,1}, {5,2}};
    vector<vector<int> >vec;
    for (int i = 0 ; i < LEN1; ++i) {
        vec.push_back(vector<int>(arr[i], arr[i] + LEN2));
    }
    s.reconstructQueue(vec);
    return 0;
}
