// 24ms, 20.73%
class Solution 
{
private:
    ListNode *temp;
    
public:
    bool isPalindrome(ListNode *head)
    {
        temp = head;
        return check(head);
    }
    
    bool check(ListNode *p)
    {
        if(nullptr == p) return true;
        bool isPal = check(p->next) & (temp->val == p->val);
        temp = temp->next;
        return isPal;
    }
};
