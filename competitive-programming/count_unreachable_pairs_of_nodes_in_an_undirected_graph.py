# https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/description/
class Solution:
    def countPairs(self, n: int, edges: List[List[int]]) -> int:
        adj_list = collections.defaultdict(list)
        for u, v in edges:
            adj_list[u].append(v)
            adj_list[v].append(u)

        visited = [False] * n

        def dfs(start):
            if visited[start]:
                return 0
            
            s = []
            s.append(start)
            visited[start] = True
            count = 0

            while len(s) > 0:
                now = s.pop()
                count += 1

                for v in adj_list[now]:
                    if not visited[v]:
                        visited[v] = True
                        s.append(v)

            return count

        total = 0
        for i in range(n):
            if not visited[i]:
                current = dfs(i)
                total += current * (n - current)
        
        return total // 2
