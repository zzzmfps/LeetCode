// 44ms, 96.74%; 10.6MB, 99.20%
static int x = []() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();

class Solution
{
public:
	int largestPerimeter(vector<int>& A)
	{
		sort(A.rbegin(), A.rend());
		for(int i = 2, size = A.size(); i < size; ++i)
			if(A[i - 2] < A[i - 1] + A[i]) return A[i - 2] + A[i - 1] + A[i];
		return 0;
	}
};
