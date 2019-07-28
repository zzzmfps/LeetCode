// 8ms, 50.19%; 13.9MB, 34.04%
auto x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
private:
    map<pair<int, int>, double> record;

public:
    double soupServings(int N)
    {
        if (N > 4800) return 1.0;
        return helper(N, N);
    }

private:
    double helper(int a, int b)
    {
        if (a <= 0 && b <= 0) return 0.5;
        if (a <= 0) return 1.0;
        if (b <= 0) return 0;
        auto p1 = make_pair(a - 100, b);
        auto p2 = make_pair(a - 75, b - 25);
        auto p3 = make_pair(a - 50, b - 50);
        auto p4 = make_pair(a - 25, b - 75);
        if (record.find(p1) == record.end()) record[p1] = helper(a - 100, b);
        if (record.find(p2) == record.end()) record[p2] = helper(a - 75, b - 25);
        if (record.find(p3) == record.end()) record[p3] = helper(a - 50, b - 50);
        if (record.find(p4) == record.end()) record[p4] = helper(a - 25, b - 75);
        return 0.25 * (record[p1] + record[p2] + record[p3] + record[p4]);
    }
};
