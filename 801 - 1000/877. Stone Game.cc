// 0 ms, 100.00%; 7.5 MB, 95.83%
#include <bits/stdc++.h>
using namespace std;

/* The first person can always pick one of the followings two sequences:
 * even seq: piles[0], piles[2], ... , piles[n-2]
 * odd  seq: piles[1], piles[3], ... , piles[n-1]
 *
 * Since sum(piles) is odd, then sum(even seq) != sum(odd seq).
 * So there exists exactly ONE out of two that leads to victory.
 */
class Solution {
public:
    bool stoneGame(const vector<int> &piles) {
        return true;
    }
};
