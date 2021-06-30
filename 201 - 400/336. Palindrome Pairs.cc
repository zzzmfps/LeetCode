// 96ms, 100.0%
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false); // toggles off the synchronization
    cin.tie(nullptr);                 // ties cin with nullptr, not cout
    return 0;
}();

class Solution {
public:
    vector<vector<int>> palindromePairs(const vector<string> &words) {
        int size1 = words.size();
        unordered_map<string, int> umap(size1);
        for (int i = 0; i < size1; ++i) umap[words[i]] = i;

        auto is_equal = [&words](int w, int i, int j) {
            j -= 1;
            while (i < j)
                if (words[w][i++] != words[w][j--]) return false;
            return true;
        };
        vector<vector<int>> res;

        for (int i = 0; i < size1; ++i) {
            int size2 = words[i].size();
            for (int j = 0; j < size2 + 1; ++j) {
                if (is_equal(i, 0, j)) {
                    auto fus = string(words[i].rbegin(), words[i].rend() - j);
                    if (fus != words[i] && umap.find(fus) != umap.end()) res.push_back(vector<int>{umap[fus], i});
                }
                if (j != size2 && is_equal(i, j, size2)) {
                    auto erp = string(words[i].rend() - j, words[i].rend());
                    if (umap.find(erp) != umap.end()) res.push_back(vector<int>{i, umap[erp]});
                }
            }
        }
        return res;
    }
};
