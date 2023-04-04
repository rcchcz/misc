# https://leetcode.com/problems/optimal-partition-of-string/
class Solution:
    def partitionString(self, s: str) -> int:
        currSet = set()
        res = 1

        for c in s:
            if c in currSet:
                res += 1
                currSet = set()
            currSet.add(c)
        
        return res