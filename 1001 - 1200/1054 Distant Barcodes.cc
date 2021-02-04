// 228ms, 64.06%; 25.1MB, 100.00%
class Solution
{
public:
    vector<int> rearrangeBarcodes(const vector<int> &barcodes)
    {
        int size = barcodes.size();
        unordered_map<int, int> m;
        m.reserve(size);
        for (auto b : barcodes) m[b] += 1;
        set<pair<int, int>> s;
        for (auto &p : m) s.insert(make_pair(p.second, p.first));

        int j = 0;
        vector<int> res(size);
        for (auto it = s.rbegin(); it != s.rend(); ++it) {
            for (int i = 0, cnt = it->first; i < cnt; i += 1, j += 2) {
                if (j >= size) j = 1;
                res[j] = it->second;
            }
        }
        return res;
    }
};
