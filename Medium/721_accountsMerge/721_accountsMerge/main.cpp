//
//  main.cpp
//  721_accountsMerge
//
//  Created by Bella Yang on 2021/1/18.
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
        parent[find(parent, x)] = find(parent, y);
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, vector<int>>emailToIndex;
        auto ite = emailToIndex.begin();
        for (int i = 0; i < accounts.size(); ++i) {
            sort(accounts[i].begin(), accounts[i].end());
            for (int j = 1; j < accounts[i].size(); ++j) {
                ite = emailToIndex.find(accounts[i][j]);
                if(ite != emailToIndex.end()){
                    ite->second.push_back(i);
                }else{
                    emailToIndex[accounts[i][j]] = vector<int>(1, i);
                }
            }
        }
        vector<int>parent(accounts.size());
        for (int i = 0; i < parent.size(); ++i) {
            parent[i] = i;
        }
        ite = emailToIndex.begin();
        while (ite != emailToIndex.end()) {
            for (int i = 1; i < ite->second.size(); ++i) {
                merge(parent, ite->second[i], ite->second[0]);
            }
            ite++;
        }
        
        ite = emailToIndex.begin();
        while (ite != emailToIndex.end()) {
            for (int i = 1; i < ite->second.size(); ++i) {
                merge(parent, ite->second[i], ite->second[0]);
            }
            ite++;
        }
        
        unordered_map<int, vector<int>>acc;
        auto iter = acc.begin();
        for (int i = 0; i < parent.size(); ++i) {
            iter = acc.find(parent[i]);
            if (iter != acc.end()) {
                iter->second.push_back(i);
            }else{
                acc[parent[i]] = vector<int>(1, i);
            }
        }
        vector<vector<string>>result;
        iter = acc.begin();
        vector<string>::iterator it;
        while (iter != acc.end()) {
            vector<string> tmp(1, accounts[iter->second[0]][0]);
            for (int i = 0; i < iter->second.size(); ++i) {
                tmp.insert(tmp.end(), accounts[iter->second[i]].begin() + 1, accounts[iter->second[i]].end());
            }
            sort(tmp.begin() + 1, tmp.end());
            it = unique(tmp.begin() + 1, tmp.end());
            result.push_back(vector<string>(tmp.begin(), it));
            iter++;
        }
        return result;
    }
};
int main(int argc, const char * argv[]) {
    vector<vector<string>> accounts = {
        {"David","David0@m.co","David1@m.co"},
        {"David","David3@m.co","David4@m.co"},
        {"David","David4@m.co","David5@m.co"},
        {"David","David2@m.co","David3@m.co"},
        {"David","David1@m.co","David2@m.co"}};
    Solution s;
    s.accountsMerge(accounts);
    return 0;
}
