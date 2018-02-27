# 46ms, 51.08%
class Solution:
    def deleteNode(self, node):
    '''This function cannot delete the last node.
    It is NOT the real deletion.
    '''
        node.val = node.next.val
        node.next = node.next.next
        
