// 136ms, 99.73%; 17.5MB, 98.08%
static int x = []() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();

class Solution
{
public:
	vector<vector<int>> imageSmoother(const vector<vector<int>> &M)
	{
		int row = M.size(), col = M[0].size();
		vector<vector<int>> res;
		res.resize(row);
		for(int i = 0; i < row; ++i) {
			res[i].resize(col);
			for(int j = 0; j < col; ++j) res[i][j] = average(M, i, j);
		}
		return res;
	}

private:
	int average(const vector<vector<int>> &M, int i, int j)
	{
		int endi = M.size(), endj = M[0].size();
		int mini = max(0, i - 1), minj = max(0, j - 1);
		int maxi = min(endi, i + 2), maxj = min(endj, j + 2);
		int sum = 0;
		for(int i = mini; i < maxi; ++i)
			for(int j = minj; j < maxj; ++j) sum += M[i][j];
		return sum / ((maxi - mini) * (maxj - minj));
	}
};
