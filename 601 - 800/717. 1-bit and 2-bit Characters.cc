// 4ms, 75.55%; 8.6MB, 100.00%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isOneBitCharacter(const vector<int> &bits) {
        int size = bits.size(), i = 0;
        while (i < size) {
            if (i + 1 == size) return true;
            i += (bits[i] ? 2 : 1);
        }
        return false;
    }
};
