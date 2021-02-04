// 4ms, 100.0%; 8.8MB, 100.0%
static int x = []() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();

class Solution
{
public:
	int hIndex(vector<int> &citations)
	{
		if(citations.empty()) return 0;
		sort(citations.begin(), citations.end(), greater<int>());
		if(citations[0] == 0) return 0;
		int size = citations.size();
		if(citations.back() >= size) return size;
		int i = 0;
		while(++i < size)
			if(citations[i - 1] >= i && citations[i] <= i) break;
		return i;
	}
};
