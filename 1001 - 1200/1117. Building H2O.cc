// 16 ms, 94.70%; 8.8 MB, 90.25%
#include <bits/stdc++.h>
using namespace std;

class H2O {
private:
    int count = 0;
    mutex mu;
    condition_variable cv;

public:
    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex> lk(mu);
        cv.wait(lk, [&]() { return count < 2; });
        releaseHydrogen();
        cv.notify_one();
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<mutex> lk(mu);
        cv.wait(lk, [&]() { return count == 2; });
        releaseOxygen();
        count = 0;
        cv.notify_all();
    }
};
