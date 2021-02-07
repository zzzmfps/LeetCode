// 226ms, 77.68%
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
private:
    unordered_map<int, int> *dists;
    int psize;

public:
    int numberOfBoomerangs(const vector<pair<int, int>> &points) {
        getAllDists(points);
        return getBoomerangsNum();
    }

private:
    void getAllDists(const vector<pair<int, int>> &points) {
        // better method: use the same 1-dimension array in every for-loop
        // to record the distance between point i and point j (dists[j] = <dist>).
        psize = points.size();
        dists = new unordered_map<int, int>[psize];
        for (int i = 0; i < psize; ++i) {
            dists[i].reserve(psize);
            for (int j = 0; j < psize; ++j) {
                int xdiff = points[i].first - points[j].first, ydiff = points[i].second - points[j].second;
                dists[i][xdiff * xdiff + ydiff * ydiff] += 1;
            }
        }
    }

    int getBoomerangsNum() {
        int sum = 0;
        for (int i = 0; i < psize; ++i)
            for (const auto &p : dists[i]) sum += p.second * (p.second - 1);
        return sum;
    }
};
