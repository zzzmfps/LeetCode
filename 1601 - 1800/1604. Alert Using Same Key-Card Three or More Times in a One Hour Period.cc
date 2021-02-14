// 304 ms, 81.46%; 111.7 MB, 37.56%
#include <bits/stdc++.h>
using namespace std;

static constexpr int MINUTES_OF_HOUR = 60;

class Solution {
public:
    vector<string> alertNames(const vector<string> &keyName, const vector<string> &keyTime) {
        map<string, set<int>> record;
        for (int i = 0; i < keyName.size(); ++i) record[keyName[i]].insert(this->toMinutes(keyTime[i]));

        vector<string> alerted;
        for (auto &&p : record) {
            if (p.second.size() < 3) continue;
            for (auto it1 = p.second.begin(), it2 = next(it1, 2); it2 != p.second.end(); ++it1, ++it2) {
                if (*it2 - *it1 <= 60) {
                    alerted.push_back(p.first);
                    break;
                }
            }
        }
        return alerted;
    }

private:
    int toMinutes(const string &time) {
        return MINUTES_OF_HOUR * (10 * time[0] + time[1] - 528) + 10 * time[3] + time[4] - 528;
    }
};
