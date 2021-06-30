// 4ms, 45.80%
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int maxChunksToSorted(const vector<int> &arr) {
        int count = 0, length = arr.size();
        int i = 0, j = 1;
        while (i < length)
            if (helper(arr, i, j)) {
                ++count;
                i = j, j += 1;
            } else {
                j += 1;
                if (j == length) {
                    count += 1;
                    break;
                }
            }
        return count;
    }

private:
    bool helper(const vector<int> &arr, int left, int right) {
        for (int i = left; i < right; ++i)
            if (arr[i] < left || arr[i] >= right) return false;
        return true;
    }
};
