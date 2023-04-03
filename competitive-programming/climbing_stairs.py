# https://leetcode.com/problems/climbing-stairs/
class Solution:
    def climbStairs(self, n: int) -> int:
        # 1 -> 1
        # 2 -> 2 (1 - 2)
        # 3 -> 3 (1,1,1 - 1,2 - 2,1)
        # 4 -> 5 (1,1,1,1 - 1,1,2 - 1,2,1 - 2,1,1 - 2,2)
        # 5 -> 8 (1,1,1,1,1 - 1,1,1,2 - 1,1,2,1 - 1,2,1,1 - 2,1,1,1 - 1,2,2 - 2,1,2 - 2,2,1)
        # (fibonacci sequence)
        
        #def steps(n):
        #    if n <= 2: return n
        #    return steps(n-1) + steps(n-2)
        # return steps(n)

        if n <= 2: return n
        
        prev1 = 1
        prev2 = 2
        current = 0
        
        for i in range(2, n):
            current = prev1 + prev2
            prev1 = prev2
            prev2 = current
        
        return current     