// 8ms, 98.87%; 9MB, 86.91%
#include <bits/stdc++.h>
using namespace std;

auto _ = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int> &deck) {
        int size = deck.size(), idx = 0;
        if (size < 2) return deck;
        vector<int> orders(size, -1);
        for (int i = 0; i < size - 1; ++i) {
            orders[idx] = i;
            idx = helper(orders, idx);
        }
        orders[helper(orders, idx, true)] = size - 1;
        sort(deck.begin(), deck.end());
        for (auto &val : orders) val = deck[val];
        return orders;
    }

private:
    int helper(const vector<int> &orders, int idx, bool isSkipped = false) {
        int size = orders.size();
        for (int j = idx + 1; j < size; ++j)
            if (orders[j] < 0) {
                if (isSkipped) return j;
                isSkipped = true;
            }
        for (int j = 1; j < idx; ++j)
            if (orders[j] < 0) {
                if (isSkipped) return j;
                isSkipped = true;
            }
        return -1;
    }
};
