// 0 ms, 100.00%; 5.9 MB, 85.26%
#include <bits/stdc++.h>
using namespace std;

/** Mathematical induction:
 * At the beginning, there's f(1)=false, f(2)=true, f(3)=false, f(4)=true
 *
 * Assuming for integer k, there's f(2*k)=true, f(2*k+1)=false
 * And then for integer k+1, we got the followings:
 * * for 2*k+2, Alice can always choose 1 to make a 2*k+1, for which f(2*k+1)=false.
 * * for 2*k+3, it is either prime or contains only odd factors so that Alice can
 * *     only make an even number for Bob, with which victory is assured.
 *
 * Therefore, the answer only depends on if it is an even number.
 */
class Solution {
public:
    bool divisorGame(int N) {
        return !(N & 1);
    }
};
