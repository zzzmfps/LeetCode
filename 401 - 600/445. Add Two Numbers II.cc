// 28ms, 100.0%; 10MB, 100.0%
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        auto r1 = reverse(l1), r2 = reverse(l2);
        add(r1, r2);
        return reverse(r1);
    }

private:
    ListNode *reverse(ListNode *l) {
        ListNode *last = nullptr, *next;
        while (l) {
            next = l->next;
            l->next = last;
            last = l, l = next;
        }
        return last;
    }

    void add(ListNode *l1, ListNode *l2) {
        bool carry = false;
        while (true) {
            l1->val += l2->val + carry;
            l1->val > 9 ? l1->val -= 10, carry = true : carry = false;
            if (!l1->next || !l2->next) break;
            l1 = l1->next, l2 = l2->next;
        }
        if (!l1->next) l1->next = l2->next;
        while (carry && l1->next) {
            l1 = l1->next;
            if (l1->val == 9) {
                l1->val = 0;
            } else {
                ++l1->val;
                carry = false;
            }
        }
        if (carry) l1->next = new ListNode(1);
    }
};
