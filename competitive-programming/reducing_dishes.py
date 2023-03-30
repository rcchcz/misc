# https://leetcode.com/problems/reducing-dishes/
class Solution:
    def maxSatisfaction(self, satisfaction: List[int]) -> int:
        N = len(satisfaction)
        satisfaction.sort()

        best = 0
        total = 0
        last = 0  

        for i in range(N-1, -1, -1):
            last += satisfaction[i]
            total += last
            best = max(best, total)
        
        return best