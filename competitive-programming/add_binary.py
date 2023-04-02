# https://leetcode.com/problems/add-binary/
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        res = ""
        carry = 0
        
        # reverse to compute digits in order (from the end to the beginning)
        a, b = a[::-1], b[::-1]

        for i in range(max(len(a), len(b))):
            # ord(a[i]) - ord("0") its a way to convert ascii to int
            digitA = ord(a[i]) - ord("0") if i < len(a) else 0
            digitB = ord(b[i]) - ord("0") if i < len(b) else 0

            total = digitA + digitB + carry
            char = str(total % 2)
            res = char + res
            carry = total  // 2

        if carry:
            res = "1" + res
        
        return res