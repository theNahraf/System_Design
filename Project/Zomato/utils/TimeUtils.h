#ifndef TIME_UTILS_H
#define TIME_UTILS_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>

using namespace std;

class TimeUtils{
public:
    static string getCurrentTime(){
        time_t now = time(0);
        char* dt =  ctime(&now);
        string s(dt);
        if(!s.empty() && s.back() ==  '\n')
            s.pop_back();
        return s;
    }
};


#endif