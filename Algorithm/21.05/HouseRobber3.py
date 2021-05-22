# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def rob(self, root: TreeNode) -> int:
        def help(node):
            if not node:
                return (0,0)
            l = help(node.left)
            r = help(node.right)
            rob = node.val + l[1] + r[1]
            not_rob = max(l) + max(r)
            return rob,not_rob
        return max(help(root))

        