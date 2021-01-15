//
//  main.cpp
//  947_removeStones
//
//  Created by Bella Yang on 2021/1/15.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
private:
    vector<int>parent;
public:
    Solution():parent(20004){
        for (int i = 0; i < parent.size(); ++i) {
            parent[i] = i;
        }
    }
    int find(int x){
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void merge(int x, int y){
        parent[find(x)] = find(y);
    }
    int removeStones(vector<vector<int>>& stones) {
        for (int i = 0; i < stones.size(); ++i) {
            merge(stones[i][0], stones[i][1] + 10001);
        }
        unordered_map<int, bool> umap;
        for (int i = 0; i < stones.size(); i++) {
            umap[find(stones[i][0])] = true;
            umap[find(stones[i][1] + 10001)] = true;
        }
        return stones.size() - umap.size();
    }
};
int main(int argc, const char * argv[]) {
    vector<vector<int>> stones = {{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}};
    Solution s;
    cout << s.removeStones(stones) << endl;
    return 0;
}
