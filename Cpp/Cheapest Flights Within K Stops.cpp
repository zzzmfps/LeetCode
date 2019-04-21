// 20ms, 79.97%; 11MB, 100.00%
static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
public:
    int findCheapestPrice(int n, const vector<vector<int>> &flights, int src, int dst, int K)
    {
        vector<int> price(n, 2e4);
        price[src] = 0;
        vector<int> tmp(price);
        for (int i = 0; i <= K; ++i) {
            for (const auto &f : flights) tmp[f[1]] = min(tmp[f[1]], price[f[0]] + f[2]);
            price = tmp;
        }
        return (price[dst] == 2e4 ? -1 : price[dst]);
    }
};
