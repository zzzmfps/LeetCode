// 176 ms, 83.35%; 67.3 MB, 63.88%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCenter(const vector<vector<int>> &edges) {
        if (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1]) return edges[0][0];
        return edges[0][1];
    }
};
