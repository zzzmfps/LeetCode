// 12ms, 99.02%
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
        vector<int> candies, limit;
        candies.resize(n), limit.reserve(n + 2);
        
        // 1, find all lowest points which equal to 1
        limit.push_back(-1);
        if (ratings[0] <= ratings[1]) candies[0] = 1, limit.push_back(0);
        for (int i = 1; i < n - 1; ++i)
            if (ratings[i - 1] >= ratings[i] && ratings[i] <= ratings[i + 1]) candies[i] = 1, limit.push_back(i);
        if (ratings[n - 2] >= ratings[n - 1]) candies[n - 1] = 1, limit.push_back(n - 1);
        limit.push_back(n);
        
        // 2, extend from points equal to 1
        for (int i = 1, c = limit.size() - 1; i < c; ++i) {
            auto &left = limit[i - 1], &pivot = limit[i], &right = limit[i + 1];
            for (int j = pivot - 1; j > left; --j) {
                if (ratings[j] <= ratings[j + 1]) break;
                candies[j] = max(candies[j], candies[j + 1] + 1);
            }
            for (int j = pivot + 1; j < right; ++j) {
                if (ratings[j - 1] >= ratings[j]) break;
                candies[j] = max(candies[j], candies[j - 1] + 1);
            }
        }
        return accumulate(candies.begin(), candies.end(), 0);
    }
};
