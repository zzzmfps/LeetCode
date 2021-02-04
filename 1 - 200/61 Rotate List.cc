// 13ms, 23.48%
class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if(!head) return head;
        ListNode *end = head, *newEnd = head;
        int i = 0;
        for(; end->next; ++i) end = end->next;
        if((k %= ++i) == 0) return head;
        for(int j = 0; j < i - k - 1; ++j) newEnd = newEnd->next;

        end->next = head;
        head = newEnd->next;
        newEnd->next = nullptr;
        return head;
    }
};
