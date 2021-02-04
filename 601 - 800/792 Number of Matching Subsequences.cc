// 116ms, 100.0%
static int x = []() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();

class Solution
{
public:
	int numMatchingSubseq(const string &S, const vector<string>& words)
	{
		int res = 0;
		set<string> exist;
		for(const auto &word : words) {
			if(exist.find(word) != exist.end()) {
				res += 1;
				continue;
			}
			int i = -1;
			for(const auto w : word) {
				i = S.find(w, i + 1);
				if(i == string::npos) break;
			}
			if(i != string::npos) res += 1;
		}
		return res;
	}
};
