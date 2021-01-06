//
//  main.cpp
//  399_calcEquation
//
//  Created by Bella Yang on 2021/1/6.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
    struct Edge{
        double value;
        int inorder;
        bool valid;
        Edge(double val=-1, int ino=false, bool v = false):value(val),inorder(ino),valid(v){}
    };
public:
    Edge dfs(map<string, bool>& is_visit, map<string, vector<pair<string,Edge>>>&graph,
             string start, string end, double val, int inorder){
        if (graph.find(start) == graph.end()) {
            return Edge(-1, 0, false);
        }
        if (start == end) {
            return Edge(val, inorder, true);
        }
        auto iter = graph.find(start);
        for (int i = 0; i < iter->second.size(); ++i) {
            if (!is_visit[iter->second[i].first]) {
                is_visit[iter->second[i].first] = true;
                double new_val = val * (iter->second[i].second.value);
                Edge edge = dfs(is_visit, graph, iter->second[i].first, end,
                                new_val,
                               inorder + iter->second[i].second.inorder);
                is_visit[iter->second[i].first] = false;
                if (edge.valid) {
                    return edge;
                }
            }
        }
        return Edge(-1, 0, false);
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values,
                                vector<vector<string>>& queries) {
        map<string, vector<pair<string, Edge>>>graph;
        auto iter = graph.begin();
        map<string, bool> is_visit;
        for (int i = 0; i < equations.size(); ++i) {
            iter = graph.find(equations[i][0]);
            is_visit[equations[i][0]] = false;
            if (iter == graph.end()) {
                graph[equations[i][0]] = vector<pair<string, Edge>>(1, pair<string, Edge>
                                                                    (equations[i][1], Edge(values[i], false)));
            }else{
                iter->second.push_back(pair<string, Edge>(equations[i][1],  Edge(values[i], false)));
            }
            iter = graph.find(equations[i][1]);
            is_visit[equations[i][1]] = false;
            if (iter == graph.end()) {
                graph[equations[i][1]] = vector<pair<string, Edge>>(1, pair<string, Edge>
                                                                    (equations[i][0], Edge(1/values[i], true)));
            }else{
                iter->second.push_back(pair<string, Edge>(equations[i][0],  Edge(1/values[i], true)));
            }
        }
        vector<double> result(queries.size());
        
        for (int i = 0; i < queries.size(); ++i) {
            is_visit[queries[i][0]] = true;
            Edge tmp1 = dfs(is_visit, graph, queries[i][0], queries[i][1], 1, 0);
            is_visit[queries[i][0]] = false;
            if (!tmp1.valid) {
                result[i] = -1;
            }else{
                is_visit[queries[i][1]] = true;
                Edge tmp2 = dfs(is_visit, graph, queries[i][1], queries[i][0], 1, 0);
                is_visit[queries[i][1]] = false;
                result[i] = tmp1.inorder <= tmp2.inorder ? tmp1.value : 1/tmp2.value;
            }
        
        }
        return result;
    }
};
int main(int argc, const char * argv[]) {
    vector<vector<string>> equations = {{"a","b"}};
    vector<double> values= {0.5};
    vector<vector<string>> queries = {{"a","b"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}};
    Solution s;
    s.calcEquation(equations, values, queries);
    return 0;
}
