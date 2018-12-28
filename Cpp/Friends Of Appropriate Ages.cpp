// 20ms, 99.01%
static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
  public:
    int numFriendRequests(vector<int> &ages)
    {
        unordered_map<int, pair<int, int>> ages1;
        ages1.reserve(ages.size());
        for (auto x : ages) ++ages1[x].first;
        for (auto &y : ages1) y.second.second = 0.5 * y.first + 7;
        
        int ret = 0;
        for (auto it1 = ages1.begin(); it1 != ages1.end(); ++it1) {
            for (auto it2 = it1; it2 != ages1.end(); ++it2) {
                auto &x = *it1, &y = *it2;
                if (it1 == it2 && x.first > x.second.second) {
                    ret += x.second.first * (x.second.first - 1);
                } else if (x.first > y.second.second && x.first < y.first) {
                    ret += x.second.first * y.second.first;
                } else if (y.first > x.second.second && y.first < x.first) {
                    ret += x.second.first * y.second.first;
                }
            }
        }
        return ret;
    }
};
