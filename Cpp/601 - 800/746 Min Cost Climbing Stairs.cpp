// 8ms, 99.84%; 8.9MB, 98.94%
static int x = []() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();

class Solution
{
public:
	int minCostClimbingStairs(vector<int> &cost)
	{
		cost.push_back(0);
		int size = cost.size();
		vector<int> dp{cost[0], cost[1]};
		dp.resize(size);
		for(int i = 2; i < size; ++i)
			dp[i] = cost[i] + min(dp[i - 2], dp[i - 1]);
		return dp.back();
	}
};
