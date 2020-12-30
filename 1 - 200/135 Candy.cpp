// 8ms, 99.78%
static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
  public:
    int candy(const vector<int> &ratings)
    {
        int n = ratings.size();
        vector<int> candies;
        candies.resize(n, 1);
        for (int i = 1; i < n; ++i)
            if (ratings[i] > ratings[i - 1]) candies[i] = candies[i - 1] + 1;
        for (int i = n - 2; i > -1; --i)
            if (ratings[i] > ratings[i + 1] && candies[i] <= candies[i + 1]) candies[i] = candies[i + 1] + 1;
        return accumulate(candies.begin(), candies.end(), 0);
    }
};
