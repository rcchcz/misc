# https://leetcode.com/problems/minimum-path-sum/
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        R, C = len(grid), len(grid[0])
        res = [[float("inf")] * (C+1) for r in range (R+1)]
        res[R-1][C] = 0

        for r in range(R-1, -1, -1):
            for c in range(C-1, -1, -1):
                res[r][c] = grid[r][c] + min(res[r+1][c], res[r][c+1])

        return res[0][0]