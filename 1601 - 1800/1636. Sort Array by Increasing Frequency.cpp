#include <algorithm>
#include <map>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> frequencySort(vector<int> &nums)
    {
        map<int, int> rec;
        for (auto n : nums) ++rec[n];
        vector<pair<int, int>> sorts;
        for (auto &&p : rec) sorts.push_back(p);
        sort(sorts.begin(), sorts.end(), [](const pair<int, int> &p1, const pair<int, int> &p2) {
            return p1.second < p2.second || p1.second == p2.second && p1.first > p2.first;
        });
        vector<int> res;
        for (auto &&p : sorts)
            for (int i = 0; i < p.second; ++i) res.push_back(p.first);
        return res;
    }
};
