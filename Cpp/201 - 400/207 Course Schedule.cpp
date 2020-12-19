// 16ms, 99.48%; 11.4MB, 94.32%
static int x = []() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();

class Solution
{
public:
	bool canFinish(int numCourses, const vector<pair<int, int>> &prerequisites)
	{
		int left = prerequisites.size();
		vector<int> cnt;
		vector<vector<int>> pre;
		cnt.resize(numCourses);
		pre.resize(numCourses);
		for(const auto &p : prerequisites) {
			++cnt[p.first];
			pre[p.second].push_back(p.first);
		}
		while(left > 0 && deleteEdge(pre, cnt, left)) continue;
		return left == 0;
	}

private:
	bool deleteEdge(const vector<vector<int>> &pre, vector<int> &cnt, int &left)
	{
		auto iter = find(cnt.begin(), cnt.end(), 0);
		if(iter == cnt.end()) return false;
		int i = distance(cnt.begin(), iter);
		cnt[i] = -1;
		for(auto j : pre[i]) --cnt[j], --left;
		return true;
	}
};
