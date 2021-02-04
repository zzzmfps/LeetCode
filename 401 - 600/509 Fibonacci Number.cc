// 4ms, 100.0%; 8.3MB, 100.0%
static int x = []() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();

class Solution
{
private:
	int fibonacci[31]{0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233,
					377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711,
					28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040};

public:
	int fib(int N) const { return fibonacci[N]; }
};
