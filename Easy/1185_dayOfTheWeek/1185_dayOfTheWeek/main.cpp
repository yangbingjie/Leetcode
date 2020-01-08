//
//  main.cpp
//  1185_dayOfTheWeek
//
//  Created by Bella Yang on 2020/1/8.
//  Copyright © 2020 Bella Yang. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        const string week_name[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        if(month <= 2){
            year--;
            month += 12;
        }
        int y = year % 100;
        int c = (year - y) / 100;
        int week = (y + (int)(y / 4) + (int)(c/4) - 2 * c + (int)(26 * (month + 1) / 10) + day - 1) % 7;
        week= ( week % 7 + 7 ) % 7;
        return week_name[week];
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.dayOfTheWeek(7, 3, 2003) << endl;
    return 0;
}
