// 8ms, 100.0%; 10.1MB, 99.48%
static int x = []() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();

class Solution
{
public:
	int orangesRotting(vector<vector<int>> &grid)
	{
		int row = grid.size(), col = grid[0].size(), fresh = 0, time = 0;
		stack<pair<int, int>> rotten;
		for(int i = 0; i < row; ++i) {
			for(int j = 0; j < col; ++j) {
				if(grid[i][j] == 1) {
					++fresh;
				} else if(grid[i][j] == 2) {
					rotten.emplace(i, j);
				}
			}
		}
		while(true) {
			stack<pair<int, int>> nxt;
			while(!rotten.empty()) {
				auto &p = rotten.top();
				int i = p.first, j = p.second;
				rotten.pop();
				if(i - 1 >= 0) helper(i - 1, j, fresh, grid, nxt);
				if(j - 1 >= 0) helper(i, j - 1, fresh, grid, nxt);
				if(i + 1 < row) helper(i + 1, j, fresh, grid, nxt);
				if(j + 1 < col) helper(i, j + 1, fresh, grid, nxt);
			}
			if(nxt.empty()) break;
			rotten.swap(nxt);
			++time;
		}
		return (fresh == 0) ? time : -1;
	}

private:
	void helper(int i, int j, int &f, vector<vector<int>> &grid, stack<pair<int, int>> &nxt)
	{
		if(grid[i][j] == 1) {
			--f, grid[i][j] = 2;
			nxt.emplace(i, j);
		}
	}
};
