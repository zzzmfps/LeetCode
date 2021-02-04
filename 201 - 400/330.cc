// 4 ms, 97.33%; 11.4 MB, 74.87%
#include <bits/stdc++.h>
using namespace std;

/* Let `miss` be the smallest number that CANNOT be formed by the sum
 * of some elements in the array, which means all numbers within [0, miss)
 * can be formed. Then the target is expand the range to [0, 1+n).
 *
 * As for each element in `nums`, it contributes to range if <= `miss`. Say,
 * * for miss=10, an elem=8  will expand range from [0, 10) to [0, 18).
 * * for miss=10, an elem=10 will expand range from [0, 10) to [0, 20).
 *
 * Yet when the elem is > `miss`, use `miss` first.
 *  * for miss=10, elem=15, use miss to expand range from [0, 10) to [0, 20).
 * Then it's able to use the elem 15.
 *
 * When `nums` is running out, strategy is always use `miss` itself.
 */
class Solution {
public:
    int minPatches(const vector<int> &nums, int n) {
        unsigned miss = 1, count = 0, i = 0;
        while (miss <= n) {
            if (i < nums.size() && nums[i] <= miss) {
                miss += nums[i++];
            } else {
                miss += miss;
                ++count;
            }
        }
        return count;
    }
};
