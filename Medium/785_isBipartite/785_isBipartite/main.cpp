//
//  main.cpp
//  785_isBipartite
//
//  Created by bella on 2020/7/16.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<bool>is_visited(graph.size(), false);
        // 0 repersent no color
        stack<int>sta;
        vector<int>colors(graph.size(), 0);
        
        int ind = 0;
        // 1 repersent red
        // -1 repersent green
        int current_color = 1;
        for (int j = 0;j < graph.size();j++) {
            if(is_visited[j]){
                continue;
            }
            current_color = -current_color;
            colors[j] = current_color;
            sta.push(j);
            while (!sta.empty()) {
                ind = sta.top();
                sta.pop();
                is_visited[ind] = true;
                current_color = colors[ind];
                current_color = -current_color;
                for (int i = 0; i < graph[ind].size(); ++i) {
                    if (is_visited[graph[ind][i]] == false) {
                        sta.push(graph[ind][i]);
                    }
                    if (colors[graph[ind][i]] == 0) {
                        colors[graph[ind][i]] = current_color;
                    }else{
                        if (colors[graph[ind][i]] != current_color) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
int main(int argc, const char * argv[]) {
    vector<vector<int>>graph;
    const int LEN1 = 2;
    int arr1[LEN1] = {1,3};
    graph.push_back(vector<int>(arr1, arr1 + LEN1));
    const int LEN2 = 2;
    int arr2[LEN2] = {0,2};
    graph.push_back(vector<int>(arr2, arr2 + LEN2));
    const int LEN3 = 2;
    int arr3[LEN3] = {1,3};
    graph.push_back(vector<int>(arr3, arr3 + LEN3));
    const int LEN4 = 2;
    int arr4[LEN4] = {0,2};
    graph.push_back(vector<int>(arr4, arr4 + LEN4));

//    const int LEN1 = 0;
//    int arr1[LEN1] = {};
//    graph.push_back(vector<int>(arr1, arr1 + LEN1));
//    const int LEN2 = 3;
//    int arr2[LEN2] = {2,4,6};
//    graph.push_back(vector<int>(arr2, arr2 + LEN2));
//    const int LEN3 = 4;
//    int arr3[LEN3] = {1,4,8,9};
//    graph.push_back(vector<int>(arr3, arr3 + LEN3));
//    const int LEN4 = 2;
//    int arr4[LEN4] = {7,8};
//    graph.push_back(vector<int>(arr4, arr4 + LEN4));
//    const int LEN5 = 4;
//    int arr5[LEN5] = {1,2,8,9};
//    graph.push_back(vector<int>(arr5, arr5 + LEN5));
//    const int LEN6 = 2;
//    int arr6[LEN6] = {6,9};
//    graph.push_back(vector<int>(arr6, arr6 + LEN6));
//    const int LEN7 = 5;
//    int arr7[LEN7] = {1,5,7,8,9};
//    graph.push_back(vector<int>(arr7, arr7 + LEN7));
//    const int LEN8 = 3;
//    int arr8[LEN8] = {3,6,9};
//    graph.push_back(vector<int>(arr8, arr8 + LEN8));
//    const int LEN9 = 5;
//    int arr9[LEN9] = {2,3,4,6,9};
//    graph.push_back(vector<int>(arr9, arr9 + LEN9));
//    const int LEN0 = 6;
//    int arr0[LEN0] = {2,4,5,6,7,8};
//    graph.push_back(vector<int>(arr0, arr0 + LEN0));
    Solution s;
    cout << s.isBipartite(graph) << endl;
    return 0;
}
