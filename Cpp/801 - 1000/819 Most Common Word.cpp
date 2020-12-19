// 8ms, 100.0%; 9.2MB, 75.23%
static int x = []() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();

class Solution
{
public:
	string mostCommonWord(string &paragraph, const vector<string> &banned)
	{
		string para = paragraph + ".";
		set<char> delim{' ', '!', '?', '\'', ',', ';', '.'};
		set<string> ban(banned.begin(), banned.end());

		map<string, int> rec;
		string tmp = "", max = "";

		for(const auto c : para) {
			if(delim.find(c) == delim.end()) {
				tmp += tolower(c);
			} else if(!tmp.empty()){
				if(ban.find(tmp) == ban.end()) {
					++rec[tmp];
					if(max.empty() || rec[tmp] > rec[max]) max = tmp;
				}
				tmp.clear();
			}
		}
		return max;
	}
};
