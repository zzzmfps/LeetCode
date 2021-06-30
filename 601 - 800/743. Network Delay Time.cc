// 90ms, 48.68ms
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>> &times, int N, int K) {
        int *dist = new int[N + 1];
        fill(dist, dist + N + 1, INT_MAX);
        dist[K] = 0;

        for (int i = 0; i < N; ++i)
            for (auto &t : times) {
                int u = t[0], v = t[1], w = t[2];
                if (dist[u] != INT_MAX && dist[v] > dist[u] + w) dist[v] = dist[u] + w;
            }
        int maxwait = 0;
        for (int i = 1; i <= N; ++i)
            if (maxwait < dist[i]) maxwait = dist[i];

        return maxwait == INT_MAX ? -1 : maxwait;
    }
};
