// 57ms
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false); // toggles off the synchronization
    cin.tie(nullptr);                 // ties cin with nullptr, not cout
    return 0;
}();

class Solution {
public:
    int maxProfitAssignment(const vector<int> &difficulty, const vector<int> &profit, vector<int> worker) {
        map<int, int> job;
        int size = difficulty.size();
        for (int i = 0; i < size; ++i) job[difficulty[i]] = max(job[difficulty[i]], profit[i]);
        sort(worker.begin(), worker.end());
        int res = 0, maxp = 0;
        auto iter = job.begin();
        for (auto ab : worker) {
            for (; iter != job.end() && ab >= iter->first; ++iter) maxp = max(maxp, iter->second);
            res += maxp;
        }
        return res;
    }
};
