// 4ms, 100.0%; 8.7MB, 96.15%
static int x = []() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();

class Solution
{
public:
	string optimalDivision(const vector<int> &nums)
	{
		string res = to_string(nums[0]);
		int end = nums.size();
		if(end == 1) return res;
		if(end == 2) return res + '/' + to_string(nums[1]);
		res += "/(" + to_string(nums[1]);
		for(int i = 2; i < end; ++i)  res += '/' + to_string(nums[i]);
		return res + ')';
	}
};
