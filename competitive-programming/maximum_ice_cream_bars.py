# https://leetcode.com/problems/maximum-ice-cream-bars/
class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        costs.sort()
        max = 0

        for c in costs:
            if coins >= c:
                coins -= c
                max += 1
            else:
                break
        
        return max