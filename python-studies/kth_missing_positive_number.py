# https://leetcode.com/problems/kth-missing-positive-number/
class Solution:
    def findKthPositive(self, arr: List[int], k: int) -> int:
        N = len(arr)
        i, j = 0, 1
        skip = []

        while i < N:
            if arr[i] != j:
                skip.append(j)
            else:
                i += 1
            j += 1
        
        cnt = len(skip)
        if cnt < k:
            return arr[-1] + (k-cnt)
        else:
            return skip[k-1]