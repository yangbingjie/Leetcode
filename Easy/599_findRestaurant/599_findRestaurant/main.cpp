//
//  main.cpp
//  599_findRestaurant
//
//  Created by bella on 2020/8/11.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        map<string, pair<int, int>>m;
        map<string, pair<int, int>>::iterator iter;
        for(int i = 0; i < list2.size(); ++i){
            m[list2[i]] = pair<int, int>(1, i);
        }
        for(int i = 0; i < list1.size(); ++i){
            iter = m.find(list1[i]);
            if(iter != m.end()){
                iter->second.first++;
                iter->second.second += i;
            }
        }
        iter = m.begin();
        int ind_sum = INT_MAX;
        vector<string>result;
        while(iter != m.end()){
            if (iter->second.first != 1) {
                if(iter->second.second < ind_sum){
                    result.clear();
                    ind_sum = iter->second.second;
                    result.push_back(iter->first);
                }else if(iter->second.second == ind_sum){
                    result.push_back(iter->first);
                }
            }
            iter++;
        }
        return result;
    }
};
int main(int argc, const char * argv[]) {
    const int LEN1 = 4;
    const int LEN2 = 4;
    string arr1[LEN1] = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
    string arr2[LEN2] = {"Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"};
    vector<string>vec1(arr1, arr1 + LEN1);
    vector<string>vec2(arr2, arr2 + LEN2);
    Solution s;
    s.findRestaurant(vec1, vec2);
    return 0;
}
