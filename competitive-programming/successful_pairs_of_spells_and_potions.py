# https://leetcode.com/problems/successful-pairs-of-spells-and-potions/
class Solution:
    def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
        # sort potions and binary search
        # O(nlogm + mlogm)
        res = []
        potions.sort()
        
        for s in spells:
            l, r = 0, len(potions)-1
            idx = len(potions) # weakest potion (furthest left) that works
            while l <= r:
                m = (l + r)//2
                if s * potions[m] >= success:
                    r = m-1
                    idx = m
                else:
                    l = m+1
            res.append(len(potions)-idx)

        return res