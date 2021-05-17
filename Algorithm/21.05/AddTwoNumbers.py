# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
    ret = ListNode()
    cur = ret
    carry = 0
    while l1 or l2 or carry:
        v1, v2 = 0, 0
        if l1:
            v1 = l1.val
            l1 = l1.next
        if l2:
            v2 = l2.val
            l2 = l2.next
        
        s = v1 + v2 + carry
        carry, s = divmod(s, 10)
        cur.next = ListNode(s)
        cur = cur.next
    return ret.next