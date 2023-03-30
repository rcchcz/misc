# https://leetcode.com/problems/length-of-last-word/
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        if s.split():
            return len(s.split()[-1])

        return 0        