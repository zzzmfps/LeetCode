/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

// space complexity S(n) = k, 8ms, 100.00%; 9.9MB, 25.55%
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (!head) return nullptr;

        ListNode *p1 = head, *p2 = head;
        while (true) {
            p1 = p1->next;
            if (!p1) return nullptr;
            p1 = p1->next;
            if (!p1) return nullptr;
            p2 = p2->next;
            if (p1 == p2) break;
        }

        int cnt = 0; // length of loop
        while (true) {
            cnt += 1;
            p1 = p1->next->next;
            p2 = p2->next;
            if (p1 == p2) break;
        }

        p1 = p2 = head;
        for (int i = 1; i < cnt; ++i) p2 = p2->next;
        while (p1 != p2->next) p1 = p1->next, p2 = p2->next;
        return p1;
    }
};
