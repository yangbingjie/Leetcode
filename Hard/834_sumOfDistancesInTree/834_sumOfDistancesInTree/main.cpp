//
//  main.cpp
//  834_sumOfDistancesInTree
//
//  Created by Bella Yang on 2020/10/6.
//

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
class Solution {
public:
    void postDfs(vector<vector<int>>&dis, vector<int>& sum_dis,vector<int>& node_num, int root, int parent){
        for (int i = 0; i < dis[root].size(); ++i) {
            if (root == dis[root][i] || dis[root][i] == parent) {
                continue;
            }
            postDfs(dis, sum_dis, node_num, dis[root][i], root);
            node_num[root] += node_num[dis[root][i]];
            sum_dis[root] += sum_dis[dis[root][i]] + node_num[dis[root][i]];
        }
    }
    void preDfs(vector<vector<int>>&dis, vector<int>& sum_dis,vector<int>& node_num, int root, int parent){
        for (int i = 0; i < dis[root].size(); ++i) {
            if (root == dis[root][i] || dis[root][i] == parent) {
                continue;
            }
            sum_dis[dis[root][i]] = sum_dis[root] - node_num[dis[root][i]] + (dis.size() - node_num[dis[root][i]]);
            preDfs(dis, sum_dis, node_num, dis[root][i], root);
        }
    }
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        vector<vector<int>>neighbor(N);
        for (int i = 0; i < edges.size(); ++i) {
            neighbor[edges[i][0]].push_back(edges[i][1]);
            neighbor[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> sum_dis(N, 0);
        vector<int> node_num(N, 1);
        postDfs(neighbor, sum_dis, node_num, 0, -1);
        preDfs(neighbor, sum_dis, node_num, 0, -1);
        return sum_dis;
    }
};
int main(int argc, const char * argv[]) {
    vector<vector<int>>edges = {{0,1},{0,2},{2,3},{2,4},{2,5},{3,6}};
    Solution s;
    s.sumOfDistancesInTree(7, edges);
    return 0;
}
