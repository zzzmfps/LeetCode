// 13ms, 23.48%
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
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head) return head;
        ListNode *end = head, *newEnd = head;
        int i = 0;
        for (; end->next; ++i) end = end->next;
        if ((k %= ++i) == 0) return head;
        for (int j = 0; j < i - k - 1; ++j) newEnd = newEnd->next;

        end->next = head;
        head = newEnd->next;
        newEnd->next = nullptr;
        return head;
    }
};
