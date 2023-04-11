# https://leetcode.com/problems/removing-stars-from-a-string/
class Solution:
    def removeStars(self, s: str) -> str:
        stack = []

        for c in s:
            if c == "*": stack and stack.pop() # make sure the stack isnt empty
            else: stack.append(c)
            
        return "".join(stack)