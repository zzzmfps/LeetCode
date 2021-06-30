// 13ms, 99.47%
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false); // toggles off the synchronization
    cin.tie(nullptr);                 // ties cin with nullptr, not cout
    return 0;
}();

class Solution {
private:
    char *distro;

public:
    bool isBipartite(const vector<vector<int>> &graph) {
        int size = graph.size();
        distro = new char[size](); // 0 - invisual char
        for (int i = 0; i < size; ++i)
            if (!distro[i] && !bipartite(graph, i, 'A')) return false;
        return true;
    }

private:
    bool bipartite(const vector<vector<int>> &graph, int idx, char type) {
        if (distro[idx])
            return distro[idx] == type;
        else
            distro[idx] = type;
        char type2 = type == 'B' ? 'A' : 'B';
        for (auto g : graph[idx])
            if (!bipartite(graph, g, type2)) return false;
        return true;
    }
};
