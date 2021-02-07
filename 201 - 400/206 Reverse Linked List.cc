// 9ms, 13.51%
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        if (!head) return head;
        ListNode *pre = head, *nxt = pre->next, *tmp = pre;
        while (nxt) {
            head = nxt;
            pre->next = nxt->next;
            nxt->next = tmp;
            nxt = pre->next;
            tmp = head;
        }
        return head;
    }
};
