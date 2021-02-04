// 4ms, 100.0%
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
  public:
    vector<Interval> insert(const vector<Interval> &intervals, Interval newInterval)
    {
        auto iter1 = intervals.begin();
        while (iter1 != intervals.end() && iter1->end < newInterval.start) ++iter1;
        auto iter2 = iter1;
        while (iter2 != intervals.end() && iter2->start <= newInterval.end) ++iter2;

        vector<Interval> res(intervals.begin(), iter1);
        res.push_back(Interval((iter1 == intervals.end() ? newInterval.start : min(newInterval.start, iter1->start)),
                               (iter2 == iter1 ? newInterval.end : max(newInterval.end, prev(iter2)->end))));
        res.insert(res.end(), iter2, intervals.end());
        return res;
    }
};
