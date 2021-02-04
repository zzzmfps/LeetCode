// 4ms, 100.0%
static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
  public:
    vector<vector<int>> largeGroupPositions(string S)
    {
        int i = 0, j = 0, size = S.size();
        vector<vector<int>> res;
        while (i + 2 < size) {
            while (j + 1 < size && S[j + 1] == S[j]) ++j;
            if (j - i > 1) res.push_back({i, j});
            i = j = j + 1;
        }
        return res;
    }
};
