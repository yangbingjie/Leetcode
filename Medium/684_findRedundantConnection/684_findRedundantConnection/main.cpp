//
//  main.cpp
//  684_findRedundantConnection
//
//  Created by Bella Yang on 2021/1/13.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int find(vector<int>&parent, int ind){
        if (parent[ind] != ind) {
            parent[ind] = find(parent, parent[ind]);
        }
        return parent[ind];
    }
    void merge(vector<int>&parent,int x, int y){
        parent[find(parent, x)] = find(parent, y);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int>parent(edges.size() + 1);
        for (int i = 1; i < parent.size(); ++i) {
            parent[i] = i;
        }
        for (int i = 0; i < edges.size(); ++i) {
            if (find(parent, edges[i][0]) != find(parent, edges[i][1])) {
                merge(parent, edges[i][0], edges[i][1]);
            }else{
                return edges[i];
            }
        }
        return vector<int>();
    }
};
int main(int argc, const char * argv[]) {
    vector<vector<int>> edges = {{1,2}, {1,3}, {2,3}};
//    vector<vector<int>> edges = {{1,2}, {2,3}, {3,4}, {1,4}, {1,5}};
    Solution s;
    s.findRedundantConnection(edges);
    return 0;
}
