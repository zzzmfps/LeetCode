// 4ms, 98.23%; 9.5MB, 78.57%
class Solution
{
public:
    int maxProfit(const vector<int> &prices)
    {
        // 4 maximum profits, when we just
        // buy 1st stock, sell 1st stock, buy 2nd stock, sell 2nk stock
        int buy1 = INT_MIN, sell1 = 0, buy2 = INT_MIN, sell2 = 0;
        for (auto p : prices) {
            sell2 = max(sell2, buy2 + p);
            buy2 = max(buy2, sell1 - p);
            sell1 = max(sell1, buy1 + p);
            buy1 = max(buy1, -p); // assuming we start with no money(that is, 0)
        }
        return sell2;
    }
};
