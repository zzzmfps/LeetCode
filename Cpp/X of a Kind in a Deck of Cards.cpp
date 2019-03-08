// 16ms, 99.72%; 12MB, 9.59%
static int x = []() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();

class Solution
{
public:
	bool hasGroupsSizeX(const vector<int> &deck)
	{
        if(deck.size() < 2) return false;
		unordered_map<int, int> rec;
		rec.reserve(2 * deck.size());
		for(auto d : deck) ++rec[d];
		int mind = min_element(rec.begin(), rec.end(),
							   [](const auto &x, const auto &y) {return x.second < y.second; })->second;
        if(mind < 2) return false;
        
		vector<int> tmp;
		tmp.reserve(mind - 1);
		for(int i = 2; i <= mind; ++i)
			if(mind % i == 0) tmp.push_back(i);

		for(auto t : tmp)
			if(all_of(rec.begin(), rec.end(), [t](const auto &p) {return p.second % t == 0; })) return true;
		return false;
	}
};
