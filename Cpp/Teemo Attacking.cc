// 18ms, 100.0%
static int x = []() {
    ios_base::sync_with_stdio(false);  // toggles off the synchronization
    cin.tie(nullptr);                  // ties cin with nullptr, not cout
    return 0;
}();

class Solution
{
  public:
    int findPoisonedDuration(const vector<int> &timeSeries, int duration)
    {
        if (timeSeries.empty() || duration == 0) return 0;
        int total = 0, beg = timeSeries[0];
        for (int i = 1; i < timeSeries.size(); ++i)
            if (timeSeries[i - 1] + duration < timeSeries[i]) {
                total += duration + timeSeries[i - 1] - beg;
                beg = timeSeries[i];
            }
        total += timeSeries.back() - beg + duration;
        return total;
    }
};
