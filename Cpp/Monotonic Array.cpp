// 40ms, 100.0%; 14.2MB, 100.0%
static int x = []() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();

class Solution
{
public:
	bool isMonotonic(const vector<int> &A)
	{
		return is_sorted(A.begin(), A.end()) || is_sorted(A.rbegin(), A.rend());
	}
};
