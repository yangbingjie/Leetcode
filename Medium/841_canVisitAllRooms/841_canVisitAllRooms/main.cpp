//
//  main.cpp
//  841_canVisitAllRooms
//
//  Created by bella on 2020/8/31.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
private:
    int visited_room;
public:
    bool dfs(vector<vector<int>>& rooms, int room_ind, vector<int>& is_visited){
        if (visited_room == rooms.size()) {
            return true;
        }
        is_visited[room_ind] = true;
        this->visited_room++;
        bool all_visited = false;
        for (int i = 0; i < rooms[room_ind].size(); ++i) {
            if (rooms[room_ind][i] != 0 && !is_visited[rooms[room_ind][i]]) {
                all_visited = dfs(rooms, rooms[room_ind][i], is_visited);
                if (all_visited) {
                    return true;
                }
            }
        }
        return false;
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> is_visited(rooms.size(), false);
        this->visited_room = 1;
        return dfs(rooms, 0, is_visited);
    }
};
int main(int argc, const char * argv[]) {
    const int ROW = 1;
    const int COL = 1;
    int arr[ROW][COL] = {{}};
    vector<vector<int>>rooms;
    for (int i = 0; i < ROW; ++i) {
        rooms.push_back(vector<int>(arr[i], arr[i] + COL));
    }
    Solution s;
    cout << s.canVisitAllRooms(rooms) << endl;
    return 0;
}
