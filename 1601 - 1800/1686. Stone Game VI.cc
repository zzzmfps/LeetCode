// 244 ms, 84.89%; 113.7 MB, 64.68%
#include <bits/stdc++.h>
using namespace std;

struct Number {
    int index, value;
    Number(int i, int v) : index(i), value(v) {}
    friend bool operator<(const Number &x, const Number &y) {
        return x.value < y.value;
    }
};

class Solution {
public:
    int stoneGameVI(const vector<int> &aliceValues, const vector<int> &bobValues) {
        /** C++20
         * using Number = pair<int, int>; // index, value
         * ...
         * auto l = [](const Number &x, const Number &y) { return x.second < y.second; };
         * priority_queue<Number, vector<Number>, decltype(l)> pq;
         */
        priority_queue<Number> pq;
        for (int i = 0; i < aliceValues.size(); ++i) pq.emplace(i, aliceValues[i] + bobValues[i]);

        int count = 0, alice = 0, bob = 0;
        while (!pq.empty()) {
            auto &n = pq.top();
            if (++count & 1) {
                alice += aliceValues[n.index];
            } else {
                bob += bobValues[n.index];
            }
            pq.pop();
        }
        return (alice == bob ? 0 : alice > bob ? 1 : -1);
    }
};
