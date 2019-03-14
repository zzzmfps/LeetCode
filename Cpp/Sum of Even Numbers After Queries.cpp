// 136ms, 99.51%; 28.3MB, 99.51%
static int x = []() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();

class Solution
{
public:
	vector<int> sumEvenAfterQueries(vector<int> &A, const vector<vector<int>> &queries)
	{
		int sum = 0;
		for(auto n : A)
			if((n & 1) == 0) sum += n;
		vector<int> res;
		res.reserve(queries.size());
		for(const auto &q : queries) {
			int i = q[0], j = q[1];
			int e1 = i & 1, e2 = A[j] & 1;
			if(e1 == e2) {
				sum += (e1 == 0) ? i : i + A[j];
			} else {
				sum -= (e1 == 0) ? 0 : A[j];
			}
			res.push_back(sum);
			A[j] += i;
		}
		return res;
	}
};
