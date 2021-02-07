// 12ms, 4.36%
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *trav = head, *last = head;
        for (int i = 0; i < n; ++i) trav = trav->next;
        while (trav && trav->next) {
            trav = trav->next;
            last = last->next;
        }
        if (!trav && last == head)
            head = last->next;
        else
            last->next = last->next->next;
        return head;
    }
};
