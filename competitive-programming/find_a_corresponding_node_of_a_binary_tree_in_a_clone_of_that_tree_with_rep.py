# https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


# Follow up: Could you solve the problem if repeated values on the tree are allowed?
class Solution:
    def getTargetCopy(self, original: TreeNode, cloned: TreeNode, target: TreeNode) -> TreeNode:
        def dfs(node1, node2):
            if not node1:
                return None
            elif node1 == target:
                return node2
            
            return dfs(node1.right, node2.right) or dfs(node1.left, node2.left)
        
        return dfs(original, cloned)