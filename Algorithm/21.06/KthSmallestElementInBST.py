# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
# k 번째 작은 수.. 중위순회를 돌고 해당하는 idx 를 리턴하면 되겠다는 생각

# BST가 자주 수정된다. 그래서 k번째 수를 자주 구해야 한다.. 이런 경우에 어떻게 최적화를 할 것인가?
# 자주 수정된다면,, 수정될 때마다 계속 순회를 돌아야 하는가? 최적화할 방법이 있는가?

class Solution:
    # recursion
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        def inorder(node: TreeNode):
            return inorder(node.left) + [node.val] + inorder(node.right) if node else []
            
        return inorder(root)[k-1]
    
    # iterative
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        stack = []
        
        while True:
            while root:
                stack.append(root)
                root = root.left
            root = stack.pop()
            k -= 1
            if not k:
                return root.val
            root = root.right