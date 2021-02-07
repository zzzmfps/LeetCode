// 24ms, 80.23%; 10.5MB, 44.44%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(const vector<vector<int>> &image, int sr, int sc, int newColor) {
        int row = image.size(), col = image[0].size(), oldColor = image[sr][sc];
        vector<vector<int>> res(image);
        vector<vector<bool>> visited(row, vector<bool>(col));
        stack<pair<int, int>> st;
        st.emplace(sr, sc);
        while (!st.empty()) {
            int r = st.top().first, c = st.top().second;
            st.pop();
            visited[r][c] = true, res[r][c] = newColor;
            if (r && !visited[r - 1][c] && image[r - 1][c] == oldColor) st.emplace(r - 1, c);
            if (c && !visited[r][c - 1] && image[r][c - 1] == oldColor) st.emplace(r, c - 1);
            if (r + 1 < row && !visited[r + 1][c] && image[r + 1][c] == oldColor) st.emplace(r + 1, c);
            if (c + 1 < col && !visited[r][c + 1] && image[r][c + 1] == oldColor) st.emplace(r, c + 1);
        }
        return res;
    }
};
