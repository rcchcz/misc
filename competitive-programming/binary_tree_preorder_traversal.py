# https://leetcode.com/problems/binary-tree-preorder-traversal/
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        ans = []

        # node, left, right
        stack = []
        if root is not None:
            stack.append(root)

        while len(stack) > 0:
            current = stack.pop()
            ans.append(current.val)
            if current.right is not None:
                stack.append(current.right)
            if current.left is not None:
                stack.append(current.left)
        
        return ans