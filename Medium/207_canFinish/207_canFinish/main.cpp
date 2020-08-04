//
//  main.cpp
//  207_canFinish
//
//  Created by bella on 2020/8/4.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
struct Node {
    int val;
    Node* next;
    Node(int v, Node* n=NULL):val(v), next(n){}
};
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>result(numCourses);
        vector<Node*>node_list(numCourses, NULL);
        vector<int>in_degree(numCourses, 0);
        Node* p;
        for (int i = 0; i < prerequisites.size(); ++i) {
            in_degree[prerequisites[i][0]]++;
            p = node_list[prerequisites[i][1]];
            if(!p){
                node_list[prerequisites[i][1]] = new Node(prerequisites[i][0]);
            }else{
                while (p->next) {
                    p = p->next;
                }
                p->next = new Node(prerequisites[i][0]);
            }
        }
        vector<int>::iterator iter;
        for (int i = 0 ; i < numCourses; ++i) {
            iter = find(in_degree.begin(), in_degree.end(), 0);
            if (iter == in_degree.end()) {
                return false;
            }
            result[i] = int(iter - in_degree.begin());
            p = node_list[result[i]];
            while (p) {
                in_degree[p->val]--;
                p = p->next;
            }
            *iter = -1;
        }
        return true;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    const int LEN1 = 2;
    const int LEN2 = 3;
    int arr[LEN2][LEN1] = {{1, 0}, {2, 0}, {0,3}};
    vector<vector<int>>pre(LEN2, vector<int>(LEN1));
    for (int i = 0; i < LEN2; ++i) {
        pre[i] = vector<int>(arr[i], arr[i] + LEN1);
    }
    cout << s.canFinish(4, pre) << endl;
    return 0;
}
