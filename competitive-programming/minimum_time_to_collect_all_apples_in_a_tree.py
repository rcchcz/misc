# https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/
class Solution:
    def minTime(self, n: int, edges: List[List[int]], hasApple: List[bool]) -> int:
        e = collections.defaultdict(list)
        for u, v in edges:
            e[u].append(v)
            e[v].append(u)
        
        def transverse(node, parent):
            if len(e[node]) == 0:
                return False, 0
            
            total = 0
            for child in e[node]:
                if child != parent:
                    r, c = transverse(child, node)
                    if r:
                        total += c
            
            if total > 0 or hasApple[node]:
                return True, total + 2
            else:
                return False, 0

        r, c = transverse(0, -1)
        if r:
            return c - 2
        return 0            