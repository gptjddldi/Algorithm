# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def recursion(self, root, res):
        if root:
            self.recursion(root.left, res)
            res.append(root.val)
            self.recursion(root.right, res)
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        res = []
        self.recursion(root, res)
        return res

    
    def inorderTraversal(self, root: TreeNode) -> List[int]:
    res, stack = [], []
    while True:
        while root:
            stack.append(root)
            root = root.left
        if not stack:
            return res
        node = stack.pop()
        res.append(node.val)
        root = node.right
    return res