// 176 ms, 22.10%; 34.3 MB, 99.15%
#include <bits/stdc++.h>
using namespace std;

/** For this question, priority_queue is not an optimal choice.
 *
 * Generally, it works fine. But in this case, its sort rule involves an
 * extra variable `curTime` which changes individually.
 *
 * It cannot transmit change to the whole container, because it is based
 * on heap, so it only exec comparation on elements that on the certain
 * path of the internal tree, not all of them.
 */
using Task = pair<int, int>; // ready, num

class Solution {
public:
    int leastInterval(const vector<char> &tasks, int n) {
        if (0 == n) return tasks.size();

        int counts[26] = {};
        for (auto &&t : tasks) ++counts[t - 65];

        int curTime = 0;
        auto sortRule = [&curTime](const Task &t1, const Task &t2) -> bool {
            if (t1.first <= curTime && t2.first <= curTime) {
                return t1.second > t2.second;
            }
            if (t1.first > curTime && t2.first > curTime) {
                return t1.first < t2.first || t1.first == t2.first && t1.second > t2.second;
            }
            return t1.first <= curTime;
        };
        vector<Task> pq;
        for (int i = 0; i < 26; ++i)
            if (counts[i]) pq.emplace_back(0, counts[i]);
        sort(pq.rbegin(), pq.rend(), sortRule);

        int res = 0;
        while (!pq.empty()) {
            auto &task = pq.back();
            if (task.first > curTime) {
                res += task.first - curTime;
                curTime = task.first;
                continue;
            }
            if (1 == task.second) {
                pq.pop_back();
            } else {
                --task.second, task.first = curTime + n + 1;
            }
            ++res, ++curTime;
            sort(pq.rbegin(), pq.rend(), sortRule);
        }
        return res;
    }
};
