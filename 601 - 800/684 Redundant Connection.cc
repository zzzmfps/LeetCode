// 4ms, 98.75%; 9.9MB, 82.35%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findRedundantConnection(const vector<vector<int>> &edges) {
        int size = edges.size();
        vector<int> list(size + 1);
        for (int i = 1; i <= size; ++i) list[i] = i;
        for (const auto &p : edges) {
            int u = p[0], v = p[1];
            int ur = findRoot(list, u), vr = findRoot(list, v);
            if (ur == vr) return vector<int>(p);
            join(list, u, v);
        }
        return vector<int>();
    }

private:
    int findRoot(vector<int> &list, int x) {
        int tmp = x;
        while (x != list[x]) x = list[x];
        while (tmp != x) {
            int tmp2 = list[tmp];
            list[tmp] = x;
            tmp = tmp2;
        }
        return x;
    }

    void join(vector<int> &list, int x, int y) {
        int xx = findRoot(list, x), yy = findRoot(list, y);
        list[xx] = yy;
    }
};
