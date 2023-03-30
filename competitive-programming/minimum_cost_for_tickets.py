# https://leetcode.com/problems/minimum-cost-for-tickets/
class Solution:
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        traveling = set(days)
        has_cache = [False] * (max(days) + 1)
        cache = [None] * (max(days) + 1)

        def min_ticket(day):
            if day <= 0:
                return 0
            
            if has_cache[day]:
                return cache[day]

            if day in traveling:
                ticket1 = min_ticket(day - 1) + costs[0]
                ticket7 = min_ticket(day - 7) + costs[1]
                ticket30 = min_ticket(day - 30) + costs[2]

                has_cache[day] = True
                cache[day] = min(ticket1, ticket7, ticket30)
                return cache[day]
            
            has_cache[day] = True
            cache[day] = min_ticket(day - 1)
            return cache[day]
        
        return min_ticket(max(days))