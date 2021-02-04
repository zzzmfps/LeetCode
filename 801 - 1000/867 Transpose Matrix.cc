// 20ms, 100.0%; 11.7MB, 93.00%
static int x = []() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();

class Solution
{
public:
	vector<vector<int>> transpose(const vector<vector<int>> &A)
	{
		if(A.empty()) return vector<vector<int>>();

		int s1 = A.size(), s2 = A[0].size();
		vector<vector<int>> ret;
		ret.resize(s2);
		for(int i = 0; i < s2; ++i) {
			ret[i].resize(s1);
			for(int j = 0; j < s1; ++j) ret[i][j] = A[j][i];
		}
		return ret;
	}
};
