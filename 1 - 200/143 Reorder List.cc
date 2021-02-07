// 48ms, 80.40%; 12.6MB, 29.41%
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode *head) {
        if (!head) return;
        ListNode *slow = head, *fast = head->next;
        while (fast) { // divide link into 2 parts
            slow = slow->next;
            fast = fast->next;
            if (fast) fast = fast->next;
        }
        ListNode *link1 = head, *link2 = slow->next;
        slow->next = nullptr;
        stack<ListNode *> st;
        while (link2) { // reverse order of link2
            st.push(link2);
            link2 = link2->next;
        }
        while (!st.empty()) { // combine 2 links
            ListNode *tmp = link1->next;
            link1->next = st.top();
            link1->next->next = tmp;
            link1 = tmp;
            st.pop();
        }
    }
};
