// 14ms, 23.04%
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode *node) {
        ListNode *del = node->next;
        node->val = del->val;
        node->next = del->next;
        delete del;
    }
};
