# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def help(self, root, res, depth):
        if not root:
            return
        if depth == len(res):
            res.append([])
        res[depth].append(root.val)

        self.help(root.left, res, depth+1)
        self.help(root.right, res, depth+1)
        
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        res = []
        self.help(root, res, 0)
        return res