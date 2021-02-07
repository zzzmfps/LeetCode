// 6ms, 100.0%
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false); // toggles off the synchronization
    cin.tie(nullptr);                 // ties cin with nullptr, not cout
    return 0;
}();

class Solution {
public:
    char nextGreatestLetter(const vector<char> &letters, char target) {
        int beg = 0, end = letters.size();
        while (beg < end) {
            int mid = beg + (end - beg) / 2;
            if (letters[mid] <= target)
                beg = mid + 1;
            else
                end = mid;
        }
        return letters[beg] > target ? letters[beg] : letters[0];
    }
};
