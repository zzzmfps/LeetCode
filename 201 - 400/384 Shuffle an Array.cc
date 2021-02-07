// 215ms, 99.85%
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false); // toggles off the synchronization
    cin.tie(nullptr);                 // ties cin with nullptr, not cout
    return 0;
}();

class Solution {
private:
    vector<int> origin;
    vector<int> shuffled;

public:
    Solution(const vector<int> &nums) : origin(nums), shuffled(nums) {}

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return origin;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        std::random_shuffle(shuffled.begin(), shuffled.end());
        return shuffled;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
