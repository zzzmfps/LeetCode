// 12ms, 100.0%
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int arrayNesting(const vector<int> &nums) {
        int size = nums.size();
        bool *isVisited = new bool[size]();
        vector<int> ret;
        for (int i = 0; i < size; ++i) {
            if (isVisited[i]) continue;
            vector<int> tmp;
            for (int j = i; !isVisited[j]; j = nums[j]) {
                tmp.push_back(j);
                isVisited[j] = true;
            }
            if (tmp.size() > ret.size()) ret.swap(tmp);
        }
        delete[] isVisited;
        return ret.size();
    }
};
