# https://leetcode.com/problems/check-array-formation-through-concatenation/
class Solution:
    def canFormArray(self, arr: List[int], pieces: List[List[int]]) -> bool:
        lookup = {p[0]:i for i, p in enumerate(pieces)}

        tmp = []

        for a in arr:
            if a in lookup:
                tmp.extend(pieces[lookup[a]])
        
        return arr == tmp