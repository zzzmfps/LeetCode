// 28ms, 81.19%; 9.7MB, 27.54%
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
static int x = []() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();

class Solution
{
public:
	ListNode *insertionSortList(ListNode *head)
	{
		if(!head || !head->next) return head;
		ListNode root(0);
		root.next = head;
		while(true) {
			while(head->next && head->val <= head->next->val)
				head = head->next;
			if(!head->next) break;
			ListNode *ins = &root;
			while(ins != head && ins->next->val < head->next->val)
				ins = ins->next;
			ListNode *tmp = head->next;
			head->next = tmp->next;
			tmp->next = ins->next;
			ins->next = tmp;
		}
		return root.next;
	}
};
