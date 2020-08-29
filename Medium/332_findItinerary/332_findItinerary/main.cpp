//
//  main.cpp
//  332_findItinerary
//
//  Created by bella on 2020/8/27.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
class Solution {
public:
    bool dfs(vector<vector<int>>& matrix, vector<int>& order, int num_ticket){
        if (0 == num_ticket) {
            return true;
        }
        for (int i = 0; i < matrix.size(); ++i) {
            if (matrix[order.back()][i] > 0) {
                matrix[order.back()][i]--;
                order.push_back(i);
                if (dfs(matrix, order, num_ticket - 1)) {
                    return true;
                }
                order.pop_back();
                matrix[order.back()][i]++;
            }
        }
        return false;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string, int>m;
        for (int i = 0; i < tickets.size(); ++i) {
            m[tickets[i][0]] = 0;
            m[tickets[i][1]] = 0;
        }
        int count = 0;
        map<string, int>::iterator iter = m.begin();
        vector<string>places(m.size());
        while (iter != m.end()) {
            places[count] = iter->first;
            iter->second = count;
            iter++;
            count++;
        }
        vector<vector<int>>matrix(count, vector<int>(count, 0));
        for (int i = 0; i < tickets.size(); ++i) {
            matrix[m[tickets[i][0]]][m[tickets[i][1]]]++;
        }
        vector<int> order;
        order.push_back(m["JFK"]);
        dfs(matrix, order, tickets.size());
        vector<string> result;
        for (int i = 0; i < order.size(); ++i) {
            result.push_back(places[order[i]]);
        }
        return result;
    }
};
int main(int argc, const char * argv[]) {
    const int LEN = 3;
    string arr[LEN][2] = {{"JFK","KUL"},{"JFK","NRT"},{"NRT","JFK"}};
    vector<vector<string>>vec;
    for (int i = 0; i < LEN; ++i) {
        vec.push_back(vector<string>(arr[i], arr[i] + 2));
    }
    Solution s;
    s.findItinerary(vec);
    return 0;
}

