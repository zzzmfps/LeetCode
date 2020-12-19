# 112ms, 59.15%; 13.3MB, 5.26%
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        num = self.__to_int(l1) + self.__to_int(l2)
        return self.__to_listnode(num)
       

    def __to_int(self, ln: ListNode) -> int:
        tmp = 0
        while ln:
            tmp = 10 * tmp + ln.val
            ln = ln.next
        return tmp


    def __to_listnode(self, n: int) -> ListNode:
        head = tmp = ListNode(0)
        for num in str(n):
            tmp.next = ListNode(int(num))
            tmp = tmp.next
        return head.next
