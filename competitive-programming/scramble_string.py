# https://leetcode.com/problems/scramble-string/
class Solution:
    def isScramble(self, s1: str, s2: str) -> bool:
        N = len(s1)      

        @cache
        def canScramble(left1, right1, left2, right2):
            if left1 == right1:
                return s1[left1] == s2[left2]
        
            for i in range(right1 - left1):
                if canScramble(left1, left1+i, left2, left2+i) and canScramble(left1+i+1, right1, left2+i+1, right2):
                    return True
                if canScramble(left1, left1+i, right2-i, right2) and canScramble(left1+i+1, right1, left2, right2-i-1):
                    return True
            return False

        return canScramble(0, N-1, 0, N-1)