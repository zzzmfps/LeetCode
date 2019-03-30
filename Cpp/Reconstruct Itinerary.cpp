// 24ms, 99.70%; 16.9MB, 32.38%
static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
private:
    const string START = "JFK";
    unordered_map<string, multiset<string>> umap;
    vector<string> res;

public:
    vector<string> findItinerary(const vector<pair<string, string>> &tickets)
    {
        for (const auto &p : tickets) umap[p.first].insert(p.second);
        visit(START);
        return vector<string>(res.rbegin(), res.rend());
    }

private:
    void visit(const string &x)
    {
        while (!umap[x].empty()) {
            string next = *umap[x].begin();
            umap[x].erase(umap[x].begin());
            visit(next);
        }
        res.push_back(x);
    }
};
