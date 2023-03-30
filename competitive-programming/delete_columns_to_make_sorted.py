# https://leetcode.com/problems/delete-columns-to-make-sorted/
class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
        row = len(strs)
        col = len(strs[0])
        del_str = 0

        for c in range(col):
            for r in range(row - 1):
                if strs[r][c] > strs[r + 1][c]:
                    del_str += 1
                    break
        
        return del_str