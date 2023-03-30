# https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/
class Solution:
    def makeConnected(self, n: int, connections: List[List[int]]) -> int:
        def dfs(visited, adj_lst, node):
            stack = [node]
            while(stack):
                v = stack.pop()
                if v not in visited:
                    visited.add(v)
                    for i in adj_lst[v]:
                        if i not in visited:
                            stack.append(i)

        # it takes n-1 edges to connect n vertices (graph theory)
        if len(connections) < n - 1: return -1

        # it takes 1 edge to connect every 2 disconnected subgraphs
        # return the number of disconnected subgraphs - 1
        adj_lst = [[] for i in range(n)]
        for i in connections:
            adj_lst[i[0]].append(i[1])
            adj_lst[i[1]].append(i[0])

        visited = set()
        disc_count = 0
        for i in range(n):
            if i not in visited:
                disc_count += 1
                dfs(visited, adj_lst, i)
        
        return disc_count - 1