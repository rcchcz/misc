# https://leetcode.com/problems/sqrtx/
class Solution:
    def mySqrt(self, x: int) -> int:
        # binary search approach, O(log n)
        res, l, r = 0, 0, x

        while l <= r:
            m = l + ((r - l) // 2)
            if m**2 > x:
                r = m - 1
            elif m**2 < x:
                l = m + 1
                res = m
            else:
                return m
        
        return res