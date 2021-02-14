//
//  main.cpp
//  765_minSwapsCouples
//
//  Created by Bella Yang on 2021/2/14.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int find(vector<int>&parent, int x){
        if (parent[x] != x) {
            parent[x] = find(parent, parent[x]);
        }
        return parent[x];
    }
    void merge(vector<int>&parent, int x, int y){
        parent[find(parent, x)] = parent[find(parent, y)];
    }
    int minSwapsCouples(vector<int>& row) {
        vector<int>parent(row.size() / 2);
        for (int i = 0; i < parent.size(); ++i) {
            parent[i] = i;
        }
        for (int i = 0; i < row.size(); i += 2) {
            merge(parent, row[i] / 2, row[i + 1] / 2);
        }
        unordered_map<int, int>m;
        for (int i = 0; i < parent.size(); ++i) {
            m[find(parent, i)]++;
        }
        int result = 0;
        auto iter = m.begin();
        while (iter != m.end()) {
            result += iter->second - 1;
            iter++;
        }
        return result;
    }
};
int main(int argc, const char * argv[]) {
    vector<int>row = {0,3, 2,5,4,1};
    Solution s;
    cout << s.minSwapsCouples(row) << endl;
    return 0;
}
