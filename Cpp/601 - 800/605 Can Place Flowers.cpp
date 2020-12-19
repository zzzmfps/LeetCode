// 16ms, 95.45%; 10.2MB, 100.0%
static int x = []() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();

class Solution
{
public:
	bool canPlaceFlowers(vector<int> &flowerbed, int n)
	{
		int count = 0;
		auto beg = flowerbed.begin(), end = flowerbed.end();
		auto iter = find(beg, end, 0);
		while(iter != end) {
			auto tmp = find(iter, end, 1);
			count += (distance(iter, tmp) + (iter == beg ? 1 : 0) + (tmp == end ? 1 : 0) - 1) / 2;
			iter = find(tmp, end, 0);
		}
		return count >= n;
	}
};
