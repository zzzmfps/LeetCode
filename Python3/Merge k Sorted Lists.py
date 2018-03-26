# 68ms, 100.0%
class Solution:
    def mergeKLists(self, lists):
        from operator import attrgetter
        
        sorted_list = []
        for lst in lists:
            while lst is not None:
                sorted_list.append(lst)
                lst = lst.next
        sorted_list = sorted(sorted_list, key = attrgetter('val'))
        dummy  = curr = ListNode(0)
        for node in sorted_list:
            curr.next = curr = node
        return dummy.next
    
