# https://leetcode.com/problems/is-subsequence/
class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        stack = list(s)

        for c in t:
            if stack and stack[0] == c:
                stack.pop(0)
        
        return stack == []