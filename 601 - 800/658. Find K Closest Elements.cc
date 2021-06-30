// 72ms, 100.0%; 13.13MB, 91.75%
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<int> findClosestElements(const vector<int> &arr, int k, int x) {
        if (arr.back() <= x) return vector<int>(arr.end() - k, arr.end());

        int i = binarySearch(arr, k, x);
        while (i > 0 && x - arr[i - 1] <= arr[i + k - 1] - x) --i;

        return vector<int>(arr.begin() + i, arr.begin() + i + k);
    }

private:
    int binarySearch(const vector<int> &arr, int k, int x) { // find first index that > x
        int size = arr.size();
        int i = 0, j = size - 1;
        while (i < j) {
            int mid = (i + j) / 2;
            if (arr[mid] <= x) {
                i = mid + 1;
            } else {
                j = mid;
            }
        }
        return min(i, size - k);
    }
};
