// 4ms, 88.16%; 8.7MB, 100.00%
class Solution
{
public:
    int twoCitySchedCost(vector<vector<int>> costs)
    {
        sort(costs.begin(), costs.end(),
             [](const vector<int> &x, const vector<int> &y) { return x[0] - x[1] < y[0] - y[1]; });
        int res = 0, mid = costs.size() >> 1;
        for (int i = 0; i < mid; ++i) res += costs[i][0];
        for (int i = mid; i < costs.size(); ++i) res += costs[i][1];
        return res;
    }
};
