// 224ms, 57.62%; 54.5MB, 33.33%
class Solution
{
private:
    int num;
    set<int> bl;
    vector<int> available;

public:
    Solution(int N, const vector<int> &blacklist)
    {
        num = N;
        bl = set(blacklist.begin(), blacklist.end());
        bl.insert(N);
        if (2 * int(blacklist.size()) > N || N < 10000) {
            available.reserve(N - blacklist.size());
            auto it = bl.begin();
            int i = 0;
            while (it != bl.end()) {
                if (i == *it) {
                    ++i, ++it;
                } else {
                    available.push_back(i++);
                }
            }
        }
    }

    int pick()
    {
        int ret;
        if (available.empty()) {
            while (true) {
                ret = rand() % num;
                if (bl.find(ret) == bl.end()) break;
            }
        } else {
            ret = available[rand() % available.size()];
        }
        return ret;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(N, blacklist);
 * int param_1 = obj->pick();
 */
