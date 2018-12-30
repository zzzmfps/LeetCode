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
        int size = gas.size();
        vector<int> gas1, cost1;
        gas1.resize(size), cost1.resize(size);
        gas1[0] = gas[0], cost1[0] = cost[0];
        for (int i = 1; i < size; ++i) {  // 1, accumulate
            gas1[i] = gas1[i - 1] + gas[i];
            cost1[i] = cost1[i - 1] + cost[i];
        }
        if (gas1.back() < cost1.back()) return -1;  // impossible

        vector<int> sol;  // 2, find possible solutions/starts
        sol.reserve(size);
        int index = 0;
        while (gas[index] >= cost[index] && index < size) ++index;
        while (gas[index] < cost[index] && index < size) ++index;
        if (index == size) return 0;  // only 1 TypeA field, and starts from index 0
        int tmp = index;
        do {
            sol.push_back(tmp);
            while (gas[tmp] >= cost[tmp]) tmp = (tmp + 1 == size ? 0 : tmp + 1);
            while (gas[tmp] < cost[tmp]) tmp = (tmp + 1 == size ? 0 : tmp + 1);
        } while (tmp != index);

        bool flag = true;  // 3, check possible solutions
        for (int i = 0, size1 = sol.size(); i < size1 - 1; ++i) {
            int left = (sol[i] == 0 ? size - 1 : sol[i] - 1);
            for (int j = 0; j < size1; ++j) {
                int obs = (sol[j] == 0 ? size - 1 : sol[j] - 1);
                int diff1 = gas1[obs] - gas1[left], diff2 = cost1[obs] - cost1[left];
                if (j > i && diff1 < diff2 || j < i && diff1 + gas1.back() < diff2 + cost1.back()) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                return sol[i];
            } else {
                flag = true;
            }
        }
        return sol.back();
    }
};
