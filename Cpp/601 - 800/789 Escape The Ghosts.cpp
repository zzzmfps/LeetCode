// 12ms, 87.80%; 9.5MB, 96.30%
static int x = []() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();

class Solution
{
public:
	bool escapeGhosts(const vector<vector<int>> &ghosts, const vector<int> &target)
	{
		int stp = abs(target[0]) + abs(target[1]);
		for(const auto &g : ghosts)
			if(stp >= abs(g[0] - target[0]) + abs(g[1] - target[1])) return false;
		return true;
	}
};
