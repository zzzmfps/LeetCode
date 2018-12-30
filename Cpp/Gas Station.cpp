// 4ms, 99.41%
static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
  public:
    int canCompleteCircuit(const vector<int> &gas, const vector<int> &cost)
    {
        if (accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(), cost.end(), 0)) return -1;
        int start = 0, tmp = 0;
        for (int i = 0, size = gas.size(); i < size; ++i) {
            tmp += gas[i] - cost[i];
            if (tmp < 0) {
                start = i + 1;
                tmp = 0;
            }
        }
        return start;
    }
};
