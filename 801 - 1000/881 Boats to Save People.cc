// 68ms, 100.0%; 14MB, 100.0%
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int numRescueBoats(vector<int> &people, int limit) {
        sort(people.begin(), people.end());
        int i = 0, j = people.size() - 1, res = 0;
        while (i <= j) {
            if (people[i] + people[j] <= limit) ++i;
            --j, ++res;
        }
        return res;
    }
};
