// 4ms, 100.0%; 8.3MB, 99.40%
static int x = []() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();

class Solution
{
public:
	int brokenCalc(int X, int Y)
	{
		int count = 0;
		while(X < Y) {
			Y & 1 ? Y += 1 : Y /= 2;
			++count;
		}
		return count + X - Y;
	}
};
