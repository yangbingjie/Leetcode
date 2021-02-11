//
//  main.cpp
//  703_KthLargest
//
//  Created by Bella Yang on 2021/2/11.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class KthLargest {
private:
    int kth;
    priority_queue<int, vector<int>, greater<int>>que;
public:
    KthLargest(int k, vector<int>& nums):kth(k) {
        for (int i = 0; i < nums.size(); ++i) {
            add(nums[i]);
        }
    }
    
    int add(int val) {
        que.push(val);
        if (que.size() > kth) {
            que.pop();
        }
        return que.top();
    }
};

int main(int argc, const char * argv[]) {
    vector<int>nums = {4, 5, 8, 2};
    KthLargest* obj = new KthLargest(3, nums);
    cout << obj->add(3) << endl;
    cout << obj->add(5) << endl;
    cout << obj->add(10) << endl;
    cout << obj->add(9) << endl;
    cout << obj->add(4) << endl;
    return 0;
}
