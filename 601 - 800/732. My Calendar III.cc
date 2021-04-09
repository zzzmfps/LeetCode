// 96 ms, 69.90%; 26.3 MB, 62.89%
#include <bits/stdc++.h>
using namespace std;

class MyCalendarThree {
private:
    map<int, int> timeline;

public:
    int book(int s, int e) {
        ++timeline[s];
        --timeline[e];
        int on = 0, k = 0;
        for (const auto &t : this->timeline) k = max(k, on += t.second);
        return k;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
