# https://leetcode.com/problems/kth-missing-positive-number/
class Solution:
    def findKthPositive(self, arr: List[int], k: int) -> int:
        N = len(arr)
        i, j = 0, 1
        skip = 0

        while i < N:
            if arr[i] != j:
                skip += 1
                if k == skip: return j
            else:
                i += 1
            j += 1
        
        return arr[-1] + (k-skip)
