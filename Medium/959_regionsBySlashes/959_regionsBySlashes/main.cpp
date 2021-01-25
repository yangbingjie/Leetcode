//
//  main.cpp
//  959_regionsBySlashes
//
//  Created by Bella Yang on 2021/1/25.
//

#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
public:
    int find(vector<int>&parent, int x){
        if (parent[x] == x) {
            return parent[x];
        }
        parent[x] = find(parent, parent[x]);
        return parent[x];
    }
    void merge(vector<int>&parent, int x, int y){
        parent[find(parent, x)] = find(parent, y);
    }
    int regionsBySlashes(vector<string>& grid) {
        vector<int>parent(4 * grid.size() * grid.size());
        for (int i = 0; i < parent.size(); ++i) {
            parent[i] = i;
        }
        int base;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid.size(); ++j) {
                base = (i * grid.size() + j) * 4;
                if (i < grid.size() - 1) {
                    merge(parent, base + 2, ((i + 1) * grid.size() + j) * 4);
                }
                if (j < grid.size() - 1) {
                    merge(parent, base + 1, (i * grid.size() + j + 1) * 4 + 3);
                }
                if (grid[i][j] == '/') {
                    merge(parent, base, base + 3);
                    merge(parent, base + 1, base + 2);
                }else if (grid[i][j] == '\\'){
                    merge(parent, base, base + 1);
                    merge(parent, base + 2, base + 3);
                }else{
                    merge(parent, base, base + 1);
                    merge(parent, base + 1, base + 2);
                    merge(parent, base + 2, base + 3);
                }
            }
        }
        unordered_set<int> s;
        for (int i = 0; i < parent.size(); ++i) {
            int fx = find(parent, i);
            s.insert(parent[i]);
        }
        return s.size();
    }
};
int main(int argc, const char * argv[]) {
    vector<string> grid = {"/\\","\\/"};
    Solution s;
    cout << s.regionsBySlashes(grid)<< endl;
    return 0;
}
