//
//  main.cpp
//  Offer11_minArray
//
//  Created by bella on 2020/7/22.
//  Copyright © 2020 bella. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minArray(vector<int>& numbers) {
        int begin = 0;
        int end = numbers.size() - 1;
        int mid = int((end - begin) / 2) + begin;
        while (begin < end) {
            if (numbers[mid] < numbers[end]) {
                end = mid;
            }else if (numbers[mid] > numbers[end]){
                begin = mid + 1;
            }else{
                end--;
            }
            mid = int((end - begin) / 2) + begin;
        }
        return numbers[begin];
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
