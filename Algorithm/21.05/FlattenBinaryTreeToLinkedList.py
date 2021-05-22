# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
# preorder, only right child
# return nothing just modify root
# flattened node -> right : 기존 트리 노드의 pre-order 다음 순서
# 상수 공간으로 해결..
# node.right = tmp
# node.right = node.left
# node.right.right = tmp
class Solution:
    def __init__(self):
        self.prev = None
        
    def flatten(self, root: TreeNode) -> None:
        if not root:
            return None
        self.flatten(root.right)
        self.flatten(root.left)
        root.right = self.prev
        root.left = None
        self.prev = root    
