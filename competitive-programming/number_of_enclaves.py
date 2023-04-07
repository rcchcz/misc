# https://leetcode.com/problems/number-of-enclaves/
class Solution:
    def numEnclaves(self, grid: List[List[int]]) -> int:
        rows, cols = len(grid), len(grid[0])

        def dfs(r, c):
            if r < 0 or c < 0 or r == rows or c == cols or not grid[r][c] or (r,c) in visited:
                return 0
            visited.add((r,c))
            res = 1
            direct = [[0,1], [0,-1], [1,0], [-1, 0]]
            for dr, dc in direct:
                res += dfs(r+dr, c+dc)
            return res
        
        visited = set()
        land, borderland = 0, 0
        for r in range(rows):
            for c in range(cols):
                land += grid[r][c]
                if grid[r][c] and (r,c) not in visited and (r in [0, rows-1] or c in [0, cols-1]):
                    borderland += dfs(r,c)
        
        return land - borderland