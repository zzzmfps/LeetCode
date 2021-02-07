// 0ms, 100.00%; 8.5MB, 88.14%
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *middleNode(ListNode *head) {
        ListNode *fast = head;
        while (fast->next) {
            fast = fast->next;
            if (fast->next) fast = fast->next;
            head = head->next;
        }
        return head;
    }
};
