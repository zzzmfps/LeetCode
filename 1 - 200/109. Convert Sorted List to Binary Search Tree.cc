// 22ms, 99.80%
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

static int x = []() {
    ios_base::sync_with_stdio(false); // toggles off the synchronization
    cin.tie(nullptr);                 // ties cin with nullptr, not cout
    return 0;
}();

class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if (!head) return nullptr;
        return toBST(head, nullptr);
    }

private:
    TreeNode *toBST(ListNode *head, ListNode *tail) {
        ListNode *fast = head, *slow = head;
        if (head == tail) return nullptr;
        while (fast != tail && fast->next != tail) {
            fast = fast->next->next;
            slow = slow->next;
        }
        TreeNode *ret = new TreeNode(slow->val);
        ret->left = toBST(head, slow);
        ret->right = toBST(slow->next, tail);
        return ret;
    }
};
