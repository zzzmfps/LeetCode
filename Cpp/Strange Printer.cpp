// 28ms, 100.0%; 9MB, 100.0%
static int x = []() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();

class Solution
{
private:
	int f[100][100];

public:
	int strangePrinter(const string &s)
	{
		memset(f, 0, sizeof(f));
		int len = s.size();
		return dp(s, 0, len - 1);
	}

private:
	int dp(const string &s, int l, int r)
	{
		if(l > r) return 0;
		if(f[l][r]) return f[l][r];
		f[l][r] = 1 + dp(s, l, r - 1);
		for(int i = l; i < r; ++i)
			if(s[i] == s[r])
				f[l][r] = min(f[l][r], dp(s, l, i) + dp(s, i + 1, r - 1));
		return f[l][r];
	}
};
