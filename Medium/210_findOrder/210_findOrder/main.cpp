//
//  main.cpp
//  210_findOrder
//
//  Created by Bella Yang on 2020/5/17.
//  Copyright © 2020 Bella Yang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int v, Node* n=NULL):val(v), next(n){}
};

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites){
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
                return vector<int>();
            }
            result[i] = int(iter - in_degree.begin());
            p = node_list[result[i]];
            while (p) {
                in_degree[p->val]--;
                p = p->next;
            }
            *iter = -1;
        }
        return result;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    const int LEN1 = 8;
    const int LEN2 = 2;
    int arr[LEN1] = {1,0,2,0,3,1,0,3};
    vector<vector<int>>vec;
    for (int i = 0; i < LEN1; i+=LEN2) {
        vec.push_back(vector<int>(arr + i, arr + i + LEN2));
    }
    vector<int>v = s.findOrder(4, vec);
    return 0;
}
