# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        ret = ListNode()
        cur = ret
        comp = 0
        while l1 or l2 or comp:
            val = comp
            if l1:
                val += l1.val
                l1 = l1.next
            if l2:
                val += l2.val
                l2 = l2.next
            if val >= 10:
                val -= 10
                comp = 1
            else:
                comp = 0
            cur.next = ListNode(val)
            cur = cur.next
        return ret.next
