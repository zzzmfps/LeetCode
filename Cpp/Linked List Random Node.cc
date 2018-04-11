// 30ms, 99.76%
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

static int x = []() {
    ios_base::sync_with_stdio(false); // toggles off the synchronization
    cin.tie(nullptr);                 // ties cin with nullptr, not cout
    return 0;
}();

class Solution
{
  private:
    ListNode *a_list;
    default_random_engine generator = default_random_engine();

  public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode *head)
        : a_list(head)
    {
    }

    /** Returns a random node's value. */
    int getRandom()
    {
        // failed to include <chrono> on leetcode.com
        // unsigned seed = chrono::system_clock::now().time_since_epoch().count();
        // accepted - default_random_engine generator(seed);
        // failed   - default_random_engine generator();
        // move generator outside the function, avoid initializing it at every function call
        uniform_real_distribution<double> urd(0.0, 1.0);

        ListNode *trav = a_list;
        int length = 0;
        while (trav)
        {
            trav = trav->next;
            ++length;
        }
        trav = a_list, length *= urd(generator);
        while (length)
        {
            trav = trav->next;
            --length;
        }
        return trav->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
