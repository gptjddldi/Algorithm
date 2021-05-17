# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def maxPathSum(self, root: TreeNode) -> int:
        ret = float("-inf")
        def help(root):
            nonlocal ret
            if not root:
                return 0
            left = max(0, help(root.left))
            right = max(0, help(root.right))

            ret = max(ret, root.val + left + right)

            return max(left, right) + root.val
        
        help(root)
        
        return ret