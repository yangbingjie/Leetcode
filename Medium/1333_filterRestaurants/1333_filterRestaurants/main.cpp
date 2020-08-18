//
//  main.cpp
//  1333_filterRestaurants
//
//  Created by bella on 2020/8/18.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    static bool is_better(pair<int, int>* i, pair<int, int>* j){
        return (i->second > j->second) || ((i->second == j->second) && (i->first > j->first));
    }
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<pair<int, int>*>filter;
        for (int i = 0; i < restaurants.size(); ++i) {
            if (!(veganFriendly == 1 && restaurants[i][2] == 0) && maxPrice >= restaurants[i][3] && maxDistance >= restaurants[i][4]) {
                filter.push_back(new pair<int, int>(restaurants[i][0], restaurants[i][1]));
            }
        }
        sort(filter.begin(), filter.end(), is_better);
        vector<int>result;
        for (int i = 0; i < filter.size(); ++i) {
            result.push_back(filter[i]->first);
        }
        return result;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    const int LEN1 = 5;
    const int LEN2 = 5;
    int arr[LEN1][LEN2]={{1,4,1,40,10},{2,8,0,50,5},{3,8,1,30,4},{4,10,0,10,3},{5,1,1,15,1}};
    vector<vector<int>>res(LEN1);
    for (int i = 0; i < LEN1; ++i) {
        res[i] = vector<int>(arr[i], arr[i] + LEN2);
    }
    s.filterRestaurants(res, 0, 50, 10);
    return 0;
}
