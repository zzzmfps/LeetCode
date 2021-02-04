// 8ms, 99.61%; 10.3MB, 25.57%
static int x = []() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();

class Solution
{
public:
	string reverseWords(const string &s)
	{
		string res = "";
		int i, j = s.size() - 1;
		while(true) {
			while(j >= 0 && s[j] == ' ') --j;
			if(j < 0) break;
			i = j;
			while(i > 0 && s[i - 1] != ' ') --i;
			if(!res.empty()) res += ' ';
			res += s.substr(i, j - i + 1);
			j = i - 1;
		}
		return res;
	}
};
