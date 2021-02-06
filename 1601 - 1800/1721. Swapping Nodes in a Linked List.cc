// 588 ms, 86.44%; 180 MB, 99.48%
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *swapNodes(ListNode *head, int k) {
        int length = 0;
        for (auto node = head; nullptr != node; node = node->next) ++length;
        int j = length + 1 - k;
        auto slow = head, fast = head;
        for (int i = abs(j - k); i > 0; --i) fast = fast->next;
        for (int i = min(j, k); i > 1; --i) slow = slow->next, fast = fast->next;
        swap(slow->val, fast->val);
        return head;
    }
};
