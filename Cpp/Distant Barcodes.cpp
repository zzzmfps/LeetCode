// 624ms, 5.12%; 21MB, 100.00%
class Solution
{
public:
    vector<int> rearrangeBarcodes(const vector<int> &barcodes)
    {
        int size = barcodes.size();
        unordered_map<int, int> tmp;
        tmp.reserve(size);
        for (auto b : barcodes) tmp[b] += 1;
        vector<pair<int, int>> count(tmp.begin(), tmp.end());
        sort(count.begin(), count.end(),
             [](const pair<int, int> &x, const pair<int, int> &y) { return x.second > y.second; }
        );

        int last = 0;
        vector<int> res(size);
        for (int i = 0; i < size; ++i) {
            int it1 = (count[0].first == last ? 1 : 0);
            res[i] = last = count[it1].first;
            count[it1].second -= 1;
            int it2 = it1 + 1;
            if (it2 == count.size() || count[it1].second >= count[it2].second) continue;
            while (it2 != count.size() && count[it1].second < count[it2].second) ++it2;
            swap(count[it1].first, count[it2 - 1].first);
            swap(count[it1].second, count[it2 - 1].second);
        }
        return res;
    }
};
