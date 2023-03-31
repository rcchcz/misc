# https://leetcode.com/problems/number-of-ways-of-cutting-a-pizza/
class Solution:
    def ways(self, pizza: List[str], k: int) -> int:
        # compute dims
        rows = len(pizza)
        cols = len(pizza[0])

        # init the prefix sum matrix
        prefix_sum = [[0 for j in range(cols+1)] for i in range(rows+1)]
        for i in range(rows-1, -1, -1):
            for j in range(cols-1, -1, -1):
                # curr cell value
                curr_cell = 1 if pizza[i][j] == 'A' else 0
                right_grid = prefix_sum[i][j+1]
                bottom_grid = prefix_sum[i+1][j]
                bottom_right_grid = prefix_sum[i+1][j+1]
                prefix_sum[i][j] = curr_cell + right_grid + bottom_grid - bottom_right_grid
        
        cache = {}
        def recurse(curr_row, curr_col, k):
            if (curr_row, curr_col, k) in cache:
                return cache[(curr_row, curr_col, k)]
            
            # base cases
            if prefix_sum[curr_row][curr_col] == 0: return 0
            if k == 0: return 1

            ans = 0

            # iterate over all possible vertical cuts
            for i in range(curr_row+1, rows):
                if prefix_sum[curr_row][curr_col] - prefix_sum[i][curr_col] > 0:
                    ans += recurse(i, curr_col, k-1)
            
            # iterate over all possible horizontal cuts
            for j in range(curr_col+1, cols):
                # making sure there is at least one apple in the left piece
                if prefix_sum[curr_row][curr_col] - prefix_sum[curr_row][j] > 0:
                    ans += recurse(curr_row, j, k-1)
            
            cache[(curr_row, curr_col, k)] = ans
            return ans
        
        return recurse(0, 0, k-1) % (10**9 + 7)