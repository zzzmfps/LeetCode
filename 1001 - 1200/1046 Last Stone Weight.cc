// 0ms, 100.00%; 8.3MB, 100.00%
auto x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        make_heap(stones.begin(), stones.end());
        while (stones.size() > 1) {
            pop_heap(stones.begin(), stones.end());
            int x = stones.back();
            stones.pop_back();
            pop_heap(stones.begin(), stones.end());
            int y = stones.back();
            if (x == y) {
                stones.pop_back();
            } else {
                stones.back() = x - y;
                push_heap(stones.begin(), stones.end());
            }
        }
        return (stones.empty() ? 0 : stones[0]);
    }
};
