// 4ms, 100.0%; 8.3MB, 100.0%
static int x = []() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();

class Solution
{
public:
	string convertToBase7(int num)
	{
		if(num == 0) return "0";
		string res = "";
		int pos = abs(num);
		while(pos) {
			int tmp = pos / 7;
			res += to_string(pos - 7 * tmp);
			pos = tmp;
		}
		if(num < 0) res += "-";
		return string(res.rbegin(), res.rend());
	}
};
