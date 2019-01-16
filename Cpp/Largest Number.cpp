// 4ms, 99.47%
static int x = []() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();

class Solution
{
public:
	string largestNumber(const vector<int> &nums)
	{
		vector<string> tmp;
		tmp.reserve(nums.size());
		for(const auto n : nums) tmp.push_back(to_string(n));
		sort(tmp.begin(), tmp.end(), [](auto &x, auto &y) {return x + y > y + x; });
		string ret = accumulate(tmp.begin(), tmp.end(), string());
		return all_of(ret.begin(), ret.end(), [](auto x) {return x == '0'; }) ? "0" : ret;
	}
};
