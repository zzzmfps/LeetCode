// 8ms, 100.0%
static int x = []() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();

class Solution
{
public:
	vector<int> topKFrequent(const vector<int> &nums, int k)
	{
		unordered_map<int, int> rec;
		for(auto n : nums) ++rec[n];
		vector<pair<int, int>> tmp(rec.begin(), rec.end());
		sort(tmp.begin(), tmp.end(), [](auto &x, auto &y) { return x.second >= y.second; });

		vector<int>ret;
		ret.reserve(k);
		for(int i = 0; i < k; ++i) ret.push_back(tmp[i].first);
		return ret;
	}
};
