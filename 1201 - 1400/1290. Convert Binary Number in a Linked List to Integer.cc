// 4ms, 58.69%; 8.3MB, 100.00%
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    int getDecimalValue(ListNode *head) {
        int res = 0;
        while (head) {
            res = res << 1 | head->val;
            head = head->next;
        }
        return res;
    }
};
