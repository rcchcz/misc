# https://leetcode.com/problems/largest-color-value-in-a-directed-graph/
class Solution:
    def largestPathValue(self, colors: str, edges: List[List[int]]) -> int:
        adj = defaultdict(list)
        for src, dst in edges:
            adj[src].append(dst)

        # return the max freq of most freq color
        def dfs(node):
            if node in path: return float("inf")
            if node in visited: return 0
            
            visited.add(node)
            path.add(node)
            
            # a -> 0, b -> 1, c -> 2 ...
            colorIndex = ord(colors[node]) - ord('a')
            count[node][colorIndex] = 1

            for nei in adj[node]:
                if dfs(nei) == float("inf"): return float("inf")
                for c in range(26): # colors consists of lowercase english letters, a-z
                    count[node][c] = max(
                        count[node][c],
                        (1 if c == colorIndex else 0) + count[nei][c]
                    )
            path.remove(node)
            return max(count[node])

        n, res = len(colors), 0
        visited, path = set(), set()
        count = [[0] * 26 for i in range(n)] # map count[node][color] -> max freq color
        for i in range(n):
            res = max(dfs(i), res)
        
        return -1 if res == float("inf") else res