// 8ms, 96.61%; 10.7MB, 87.06%
#include <bits/stdc++.h>
using namespace std;

auto _ = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    bool canVisitAllRooms(const vector<vector<int>> &rooms) {
        int count = 1, nums = rooms.size();
        bool *arr = new bool[nums]{true};
        vector<int> next = {0};

        for (int i = 0; i < next.size(); ++i) {
            for (const auto x : rooms[next[i]])
                if (!arr[x]) {
                    next.push_back(x);
                    arr[x] = true;
                    ++count;
                }
            if (count == nums) return true;
        }
        return false;
    }
};
