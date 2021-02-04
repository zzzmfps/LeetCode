// some other methods, notes and comparisons are written here:
// https://github.com/zzzmfps/LeetCode/blob/master/Python3/Perfect%20Squares.py

// 4ms, 100.0%; 8.4MB, 89.77%
static int x = []() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();

class Solution
{
public:
	int numSquares(int n)
	{
		auto l = [](int n) {return n == pow(int(sqrt(n)), 2); };
		if(l(n)) return 1;
		while((n & 3) == 0) n >>= 2;
		if((n & 7) == 7) return 4;
		for(int i = 0, end = 1 + int(sqrt(n)); i < end; ++i)
			if(l(n - i * i)) return 2;
		return 3;
	}
};
