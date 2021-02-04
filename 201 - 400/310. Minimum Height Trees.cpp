// 156 ms, 37.16%; 38.8 MB, 31.80%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, const vector<vector<int>> &edges) {
        vector<unordered_set<int>> graph(n);
        for (auto &&e : edges) {
            graph[e[0]].insert(e[1]);
            graph[e[1]].insert(e[0]);
        }

        vector<bool> pruned(n);
        int leftCount = n;
        while (leftCount > 2) {
            vector<int> nodes;
            for (int i = 0; i < graph.size(); ++i)
                if (1 == graph[i].size()) nodes.push_back(i);
            for (auto &&n : nodes) {
                int connected = *graph[n].begin();
                graph[n].clear();
                graph[connected].erase(n);
                pruned[n] = true, --leftCount;
            }
        }

        vector<int> res;
        for (int i = 0; i < n; ++i)
            if (!pruned[i]) res.push_back(i);
        return res;
    }
};
