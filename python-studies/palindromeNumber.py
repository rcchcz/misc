# https://leetcode.com/problems/palindrome-number/
class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False
        
        aux = x
        b = 0
        while aux:
            b = b * 10 + aux % 10
            aux //= 10
            
        return x == b
