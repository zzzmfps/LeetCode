// 16ms, 96.80%; 9.7MB, 100.00%
class Solution
{
public:
    int balancedString(const string &s)
    {
        int a[4] = {}, avg = s.size() >> 2, ret = s.size();
        for (auto c : s) a[toInt(c)] += 1;
        for (int i = 0; i < 4; ++i) a[i] = max(0, a[i] - avg);
        if (all_of(a, a + 4, [](int x) { return x == 0; })) return 0;
        for (int i = 0, j = 0, size = s.size(); j < size; ++j) {
            int cur = toInt(s[j]);
            a[cur] -= 1;
            if (a[cur] == 0 && all_of(a, a + 4, [](int x) { return x <= 0; })) {
                while (++a[toInt(s[i++])] <= 0) continue;
                ret = min(ret, j - i + 2);
            }
        }
        return ret;
    }

private:
    int toInt(char c)
    {
        switch (c) {
            case 'Q': return 0;
            case 'W': return 1;
            case 'E': return 2;
            case 'R': return 3;
        }
        return -1;
    }
};
