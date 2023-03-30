# https://leetcode.com/problems/max-points-on-a-line/
class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        best = 0
        for x0, y0 in points:
            lookup = collections.Counter()

            for x1, y1 in points:
                dx, dy = x1 - x0, y1 - y0
                if dx == 0 and dy == 0:
                    continue
                
                g = gcd(dx, dy)
                dx /= g
                dy /= g
                lookup[(dx, dy)] += 1
            
            best = max(best, max(lookup.values(), default=0) + 1)
        
        return best