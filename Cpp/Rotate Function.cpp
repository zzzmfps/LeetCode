// 4ms, 100.0%
static int x = []() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();

class Solution
{
public:
	int maxRotateFunction(const vector<int>& A)
	{
		int res = 0, sum = accumulate(A.begin(), A.end(), 0), size = A.size();
		for(int i = 0; i < size; ++i) res += i * A[i];
		int tmp = res;
		for(int i = 0; i < size - 1; ++i) {
			tmp = tmp - sum + size * A[i];
			res = max(res, tmp);
		}
		return res;
	}
};
