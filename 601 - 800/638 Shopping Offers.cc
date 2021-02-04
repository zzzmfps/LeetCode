// 4ms, 100.0%; 9.3MB, 100.0%
static int x = []() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();

void operator +=(vector<int> &a, const vector<int> &b)
{
	for(int i = 0, size = a.size(); i < size; ++i) a[i] += b[i];
}

void operator -=(vector<int> &a, const vector<int> &b)
{
	for(int i = 0, size = a.size(); i < size; ++i) a[i] -= b[i];
}

bool operator >=(const vector<int> &a, const vector<int> &b)
{
	for(int i = 0, size = a.size(); i < size; ++i)
		if(a[i] < b[i]) return false;
	return true;
}

int operator *(const vector<int> &a, const vector<int> &b)
{
	int res = 0;
	for(int i = 0, size = a.size(); i < size; ++i) res += a[i] * b[i];
	return res;
}

class Solution
{
public:
	int shoppingOffers(const vector<int> &price, vector<vector<int>> &special, vector<int> &needs)
	{
		for(int i = special.size() - 1; i >= 0; --i)
			if(!(needs >= special[i]) || price * special[i] <= special[i].back())
				special.erase(special.begin() + i);
		return dfs(price, special, needs);
	}

private:
	int dfs(const vector<int> &price, const vector<vector<int>> &special, vector<int> &needs)
	{
		int cost = price * needs;
		for(const auto &sp : special)
			if(needs >= sp) {
				needs -= sp;
				cost = min(cost, sp.back() + dfs(price, special, needs));
				needs += sp;
			}
		return cost;
	}
};
